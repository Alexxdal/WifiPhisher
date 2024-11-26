const char admin_page_settings[] = 
    "var ssid = \"%s\";"
    "var password = \"%s\";"
    "var channel = \"%d\";";

const char admin_page_header[] = 
    "<!DOCTYPE html>\n"
    "<html lang=\"en\">\n"
    "<head>\n"
    "    <meta charset=\"UTF-8\">\n"
    "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
    "    <title>ESP32 Configuration</title>\n"
    "    <style>\n"
    "        body {\n"
    "            font-family: Arial, sans-serif;\n"
    "            margin: 0;\n"
    "            padding: 0;\n"
    "        }\n"
    "        .tabs {\n"
    "            display: flex;\n"
    "            cursor: pointer;\n"
    "            background-color: #333;\n"
    "            color: white;\n"
    "            justify-content: space-around;\n"
    "            padding: 10px 0;\n"
    "        }\n"
    "        .tabs div {\n"
    "            flex: 1;\n"
    "            text-align: center;\n"
    "            padding: 10px;\n"
    "        }\n"
    "        .tabs div:hover {\n"
    "            background-color: #555;\n"
    "        }\n"
    "        .tabs .active {\n"
    "            background-color: #555;\n"
    "            font-weight: bold;\n"
    "        }\n"
    "        .tab-content {\n"
    "            display: none;\n"
    "            padding: 20px;\n"
    "        }\n"
    "        .tab-content.active {\n"
    "            display: block;\n"
    "        }\n"
    "        input[type=\"text\"], input[type=\"password\"], select {\n"
    "            width: 95%;\n"
    "            padding: 10px;\n"
    "            margin: 10px 0;\n"
    "            border: 1px solid #ccc;\n"
    "            border-radius: 5px;\n"
    "        }\n"
    "        button {\n"
    "            padding: 10px 20px;\n"
    "            background-color: #333;\n"
    "            color: white;\n"
    "            border: none;\n"
    "            border-radius: 5px;\n"
    "            cursor: pointer;\n"
    "        }\n"
    "        button:hover {\n"
    "            background-color: #555;\n"
    "        }\n"
    "    </style>\n"
    "</head>\n";

const char admin_page_body[] =
    "<body>\n"
    "    <div class=\"tabs\">\n"
    "        <div id=\"tab-settings\" class=\"active\">Hotspot Settings</div>\n"
    "        <div id=\"tab-eviltwin\">EVIL TWIN</div>\n"
    "        <div id=\"tab-fakeap\">FAKEAP</div>\n"
    "    </div>\n"
    "    <div id=\"content-settings\" class=\"tab-content active\">\n"
    "        <h2>Hotspot Settings</h2>\n"
    "        <form id=\"hotspot-form\" action=\"/save_ap\" method=\"post\">\n"
    "            <label for=\"ssid\">SSID:</label><br>\n"
    "            <input type=\"text\" id=\"ssid\" name=\"ssid\" placeholder=\"Enter SSID\" required><br>\n"
    "            <label for=\"password\">Password:</label><br>\n"
    "            <input type=\"text\" id=\"password\" name=\"password\" placeholder=\"Enter Password\"><br>\n"
    "            <label for=\"channel\">Channel:</label><br>\n"
    "            <input type=\"text\" id=\"channel\" name=\"channel\" placeholder=\"Enter Channel (1-13)\" required><br>\n"
    "            <button type=\"submit\">Save Settings</button>\n"
    "        </form>\n"
    "    </div>\n"
    "    <div id=\"content-eviltwin\" class=\"tab-content\">\n"
    "        <h2>EVIL TWIN</h2>\n"
    "        <p>Scan for Wi-Fi networks and select a target for the attack.</p>\n"
    "        <div>\n"
    "            <label for=\"attack-scenario\">Select Attack Scenario:</label>\n"
    "            <select id=\"attack-scenario\" name=\"attack-scenario\">\n"
    "                <option value=\"0\">Firmware Upgrade</option>\n"
    "                <option value=\"1\">Fake web-based network manager</option>\n"
    "                <option value=\"2\">Plugin Update</option>\n"
    "                <option value=\"3\">OAuth Login</option>\n"
    "            </select>\n"
    "        </div>\n"
    "        <button id=\"scan-btn\">Scan Networks</button>\n"
    "        <div id=\"network-list\">\n"
    "            <h3>Available Networks:</h3>\n"
    "            <table class=\"wifi-table\">\n"
    "                <thead>\n"
    "                    <tr>\n"
    "                        <th>SSID</th>\n"
    "                        <th>Signal</th>\n"
    "                        <th>Channel</th>\n"
    "                        <th>BSSID</th>\n"
    "                        <th>Auth Mode</th>\n"
    //"                        <th>Pairwise Cipher</th>\n"
    //"                        <th>Group Cipher</th>\n"
    "                        <th>WPS</th>\n"
    "                        <th>Action</th>\n"
    "                    </tr>\n"
    "                </thead>\n"
    "                <tbody id=\"wifi-networks\">\n"
    "                    <!-- Populated dynamically -->\n"
    "                </tbody>\n"
    "            </table>\n"
    "        </div>\n"
    "    </div>\n"
    "    <div id=\"content-fakeap\" class=\"tab-content\">\n"
    "        <h2>FAKEAP</h2>\n"
    "        <p>Configure and monitor the Fake Access Point settings here.</p>\n"
    "    </div>\n"
    "    <style>\n"
    "        .wifi-table {\n"
    "            width: 100%;\n"
    "            border-collapse: collapse;\n"
    "            margin-top: 20px;\n"
    "        }\n"
    "        .wifi-table th, .wifi-table td {\n"
    "            border: 1px solid #ccc;\n"
    "            padding: 10px;\n"
    "            text-align: left;\n"
    "        }\n"
    "        .wifi-table th {\n"
    "            background-color: #f4f4f4;\n"
    "            font-weight: bold;\n"
    "        }\n"
    "        .wifi-table tr:nth-child(even) {\n"
    "            background-color: #f9f9f9;\n"
    "        }\n"
    "        .wifi-table tr:hover {\n"
    "            background-color: #f1f1f1;\n"
    "        }\n"
    "        .select-btn {\n"
    "            background-color: #333;\n"
    "            color: white;\n"
    "            border: none;\n"
    "            border-radius: 5px;\n"
    "            padding: 5px 10px;\n"
    "            cursor: pointer;\n"
    "        }\n"
    "        .select-btn:hover {\n"
    "            background-color: #555;\n"
    "        }\n"
    "    </style>\n"
    "    <script>\n"
    "        function selectTarget(ssid, bssid, channel, signal, pairwise_cipher, group_cipher) {\n"
    "            const attackScenario = document.getElementById('attack-scenario').value;\n"
    "            const targetData = `ssid=${ssid}&bssid=${bssid}&channel=${channel}&signal=${signal}&group=${group_cipher}&pairwise=${pairwise_cipher}&scheme=${attackScenario}`;\n"
    "            fetch('/evil_twin', {\n"
    "                method: 'POST',\n"
    "                headers: {\n"
    "                    'Content-Type': 'application/x-www-form-urlencoded'\n"
    "                },\n"
    "                body: targetData\n"
    "            })\n"
    "            .then(response => {\n"
    "                if (response.ok) {\n"
    "                    alert(`Target ${ssid} selezionato e inviato al server.`);\n"
    "                } else {\n"
    "                    alert('Errore invio del target al server.');\n"
    "                }\n"
    "            })\n"
    "            .catch(error => {\n"
    "                console.error('Errore durante la richiesta POST:', error);\n"
    "                alert('Errore durante la richiesta POST.');\n"
    "            });\n"
    "        }\n"
    "        document.getElementById('ssid').value = ssid;\n"
    "        document.getElementById('password').value = password;\n"
    "        document.getElementById('channel').value = channel;\n"
    "        const tabs = document.querySelectorAll('.tabs div');\n"
    "        const contents = document.querySelectorAll('.tab-content');\n"
    "        tabs.forEach(tab => {\n"
    "            tab.addEventListener('click', () => {\n"
    "                tabs.forEach(t => t.classList.remove('active'));\n"
    "                contents.forEach(c => c.classList.remove('active'));\n"
    "                tab.classList.add('active');\n"
    "                const contentId = `content-${tab.id.split('-')[1]}`;\n"
    "                document.getElementById(contentId).classList.add('active');\n"
    "            });\n"
    "        });\n"
    "        document.getElementById('scan-btn').addEventListener('click', () => {\n"
    "            fetch('/scan_networks')\n"
    "                .then(response => response.json())\n"
    "                .then(data => {\n"
    "                    const networkList = document.getElementById('wifi-networks');\n"
    "                    networkList.innerHTML = '';\n"
    "                    data.forEach(network => {\n"
    "                        const row = document.createElement('tr');\n"
    "                        row.innerHTML = `\n"
    "                            <td>${network.ssid}</td>\n"
    "                            <td>${network.signal} dBm</td>\n"
    "                            <td>${network.channel}</td>\n"
    "                            <td>${network.bssid}</td>\n"
    "                            <td>${network.authmode}</td>\n"
    "                            <td style=\"display:none;\">${network.pairwise_cipher}</td>\n"
    "                            <td style=\"display:none;\">${network.group_cipher}</td>\n"
    "                            <td>${network.wps ? 'Yes' : 'No'}</td>\n"
    "                            <td><button class='select-btn' onclick='selectTarget(\"${network.ssid}\", \"${network.bssid}\", \"${network.channel}\", \"${network.signal}\", \"${network.pairwise_cipher}\", \"${network.group_cipher}\")'>Select</button></td>\n"
    "                        `;\n"
    "                        networkList.appendChild(row);\n"
    "                    });\n"
    "                })\n"
    "                .catch(error => {\n"
    "                    console.error('Error scanning networks:', error);\n"
    "                });\n"
    "        });\n"
    "    </script>\n"
    "</body>\n"
    "</html>\n";