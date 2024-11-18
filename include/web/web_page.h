#ifndef _CAPTIVE_PAGE_H
#define _CAPTIVE_PAGE_H

const char *HTML_PAGE = 
    "<!DOCTYPE html>"
    "<html>"
    "<head>"
    "<title>Captive Portal</title>"
    "<meta charset=\"UTF-8\">"
    "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
    "</head>"
    "<body>"
    "<h1>Benvenuto al Captive Portal</h1>"
    "<p>Per accedere a Internet, completa il modulo qui sotto.</p>"
    "<form action=\"/submit\" method=\"POST\">"
    "  <label for=\"username\">Nome utente:</label><br>"
    "  <input type=\"text\" id=\"username\" name=\"username\"><br>"
    "  <label for=\"password\">Password:</label><br>"
    "  <input type=\"password\" id=\"password\" name=\"password\"><br><br>"
    "  <input type=\"submit\" value=\"Accedi\">"
    "</form>"
    "</body>"
    "</html>";


#endif