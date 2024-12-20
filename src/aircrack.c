#include <mbedtls/md.h>
#include <mbedtls/aes.h>
#include <mbedtls/sha1.h>
#include <mbedtls/pkcs5.h>
#include <string.h>
#include <stdio.h>
#include "esp_log.h"
#include "utils.h"
#include "aircrack.h"


#define PMKID_LEN 16
#define WPA_PASSPHRASE_MAX_LEN 64
#define WPA_SSID_MAX_LEN 32
#define WPA_PTK_LEN 64

static const char *TAG = "AIRCRACK";


/* Static declarations */
static void calculate_pmk(const char *passphrase, const char *ssid, size_t ssid_len, uint8_t *pmk);
static void calculate_ptk(const uint8_t *pmk, const uint8_t *mac_ap, const uint8_t *mac_sta,
                   const uint8_t *anonce, const uint8_t *snonce, uint8_t *ptk);
static void calculate_mic(const uint8_t *ptk, const uint8_t *eapol, size_t eapol_len, uint8_t *mic);
static void calculate_pmkid(const uint8_t *pmk, const uint8_t *mac_ap, const uint8_t *mac_sta, uint8_t *pmkid);


static void calculate_pmk(const char *passphrase, const char *ssid, size_t ssid_len, uint8_t *pmk) 
{
    mbedtls_pkcs5_pbkdf2_hmac_ext(MBEDTLS_MD_SHA1, (const unsigned char *)passphrase, strlen(passphrase), (const unsigned char *)ssid, ssid_len, 4096, 32, pmk);
}


static void calculate_ptk(const uint8_t *pmk, const uint8_t *mac_ap, const uint8_t *mac_sta,
                          const uint8_t *anonce, const uint8_t *snonce, uint8_t *ptk) 
{
    const char *label = "Pairwise key expansion";  // Standard WPA2 label
    uint8_t data[76] = { 0 };   // Concatenation of MAC addresses and nonces
    uint8_t input[128] = { 0 }; // Buffer for HMAC input
    uint8_t temp[20] = { 0 };   // Temporary buffer for each HMAC-SHA1 block
    size_t label_len = strlen(label);

    // Concatenate MAC addresses in lexicographical order
    if (memcmp(mac_ap, mac_sta, 6) < 0) {
        memcpy(data, mac_ap, 6);
        memcpy(data + 6, mac_sta, 6);
    } else {
        memcpy(data, mac_sta, 6);
        memcpy(data + 6, mac_ap, 6);
    }

    // Concatenate nonces in lexicographical order
    if (memcmp(anonce, snonce, 32) < 0) {
        memcpy(data + 12, anonce, 32);
        memcpy(data + 44, snonce, 32);
    } else {
        memcpy(data + 12, snonce, 32);
        memcpy(data + 44, anonce, 32);
    }

    // Initialize counter to 0
    uint8_t counter = 0;
    size_t bytes_generated = 0;

    while (bytes_generated < WPA_PTK_LEN) {
        // Prepare the input: label + null byte + data + counter
        memcpy(input, label, label_len);            // Label
        input[label_len] = 0x00;                    // Null byte
        memcpy(input + label_len + 1, data, sizeof(data)); // Data (MAC + Nonce)
        input[label_len + 1 + sizeof(data)] = counter;  // Counter

        size_t input_len = label_len + 1 + sizeof(data) + 1;

        // Calculate HMAC-SHA1 block
        mbedtls_md_context_t ctx;
        const mbedtls_md_info_t *info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA1);
        mbedtls_md_init(&ctx);
        mbedtls_md_setup(&ctx, info, 1);
        mbedtls_md_hmac_starts(&ctx, pmk, 32);
        mbedtls_md_hmac_update(&ctx, input, input_len);
        mbedtls_md_hmac_finish(&ctx, temp);
        mbedtls_md_free(&ctx);

        // Copy generated bytes into PTK buffer
        size_t bytes_to_copy = (WPA_PTK_LEN - bytes_generated > 20) ? 20 : WPA_PTK_LEN - bytes_generated;
        memcpy(ptk + bytes_generated, temp, bytes_to_copy);
        bytes_generated += bytes_to_copy;
        counter++;
    }
}


static void calculate_mic(const uint8_t *ptk, const uint8_t *eapol, size_t eapol_len, uint8_t *mic) 
{
    uint8_t hmac_output[20] = { 0 };
    mbedtls_md_context_t ctx;
    const mbedtls_md_info_t *info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA1);
    mbedtls_md_init(&ctx);
    mbedtls_md_setup(&ctx, info, 1);
    mbedtls_md_hmac_starts(&ctx, ptk, 16);
    mbedtls_md_hmac_update(&ctx, eapol, eapol_len);
    mbedtls_md_hmac_finish(&ctx, hmac_output);
    mbedtls_md_free(&ctx);
    memcpy(mic, hmac_output, 16);
}


static void calculate_pmkid(const uint8_t *pmk, const uint8_t *mac_ap, const uint8_t *mac_sta, uint8_t *pmkid) 
{
    const char *pmk_name = "PMK Name";  // Etichetta utilizzata per generare PMKID
    uint8_t data[20] = { 0 };  // Lunghezza: 8 ("PMK Name") + 6 (MAC AP) + 6 (MAC STA)
    memcpy(data, pmk_name, 8);
    memcpy(data + 8, mac_ap, 6);
    memcpy(data + 14, mac_sta, 6);

    mbedtls_md_context_t ctx;
    const mbedtls_md_info_t *info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA1);

    mbedtls_md_init(&ctx);
    mbedtls_md_setup(&ctx, info, 1);
    mbedtls_md_hmac_starts(&ctx, pmk, 32);  // PMK come chiave HMAC
    mbedtls_md_hmac_update(&ctx, data, sizeof(data));
    mbedtls_md_hmac_finish(&ctx, pmkid);  // Il risultato è il PMKID (primi 16 byte)

    mbedtls_md_free(&ctx);
}


bool verify_password(const char *passphrase, const char *ssid, size_t ssid_len,
                     const uint8_t *mac_ap, const uint8_t *mac_sta,
                     const uint8_t *anonce, const uint8_t *snonce,
                     const uint8_t *eapol, size_t eapol_len,
                     const uint8_t *expected_mic) 
{
    uint8_t pmk[32] = { 0 }; /* Master key */
    uint8_t ptk[WPA_PTK_LEN] = { 0 }; /* Transient key */
    uint8_t calculated_mic[16] = { 0 };

    calculate_pmk(passphrase, ssid, ssid_len, pmk);
    calculate_ptk(pmk, mac_ap, mac_sta, anonce, snonce, ptk);
    calculate_mic(ptk, eapol, eapol_len, calculated_mic);
    
    bool ret = memcmp(calculated_mic, expected_mic, 16) == 0;
    if(ret == true)
    {
        ESP_LOGI(TAG, "Password \"%s\" verified with handshake!.", passphrase);
    }
    return ret;
}


bool verify_pmkid(const char *passphrase, const char *ssid, size_t ssid_len,
                  const uint8_t *mac_ap, const uint8_t *mac_sta,
                  const uint8_t *expected_pmkid) {
    uint8_t pmk[32] = { 0 };    // PMK è lungo 32 byte
    uint8_t pmkid[20] = { 0 };  // PMKID è lungo 16 byte

    calculate_pmk(passphrase, ssid, ssid_len, pmk);
    calculate_pmkid(pmk, mac_ap, mac_sta, pmkid);

    bool ret = memcmp(pmkid, expected_pmkid, PMKID_LEN) == 0;
    if(ret == true)
    {
        ESP_LOGI(TAG, "Password \"%s\" verified with PMKID!.", passphrase);
    }
    return ret;
}