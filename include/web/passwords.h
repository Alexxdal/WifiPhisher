
const char password_page[] = 
"<!DOCTYPE html>\n"
"<html lang=\"en\">\n"
"<head>\n"
"    <meta charset=\"UTF-8\">\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"    <title>Password Viewer</title>\n"
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
"        }\n"
"        textarea {\n"
"            width: 80%;\n"
"            height: 300px;\n"
"            margin: 20px 0;\n"
"            font-family: monospace;\n"
"            font-size: 16px;\n"
"            padding: 10px;\n"
"            border: 1px solid #ccc;\n"
"            border-radius: 5px;\n"
"            resize: none;\n"
"        }\n"
"        button {\n"
"            padding: 10px 20px;\n"
"            font-size: 16px;\n"
"            color: white;\n"
"            background-color: #007bff;\n"
"            border: none;\n"
"            border-radius: 5px;\n"
"            cursor: pointer;\n"
"        }\n"
"        button:hover {\n"
"            background-color: #0056b3;\n"
"        }\n"
"    </style>\n"
"</head>\n"
"<body>\n"
"    <h1>Saved Passwords</h1>\n"
"    <textarea id=\"passwords\" readonly>Loading passwords...</textarea>\n"
"    <button onclick=\"fetchPasswords()\">Update Passwords</button>\n"
"    <script>\n"
"\tasync function fetchPasswords() {\n"
"\t\tconst textarea = document.getElementById('passwords-textarea');\n"
"\t\ttextarea.value = \"Loading passwords...\";\n"
"\t\ttry {\\n\"\n"
"\t\tconst response = await fetch('/get_passwords', {\n"
"\t\t\tmethod: 'POST',\n"
"\t\t\theaders: {\n"
"\t\t\t\t'Content-Type': 'application/json'\n"
"\t\t\t},\n"
"\t\t\tbody: JSON.stringify({ action: 'fetch_passwords' })\n"
"\t\t});\n"
"\t\t\tif (response.ok) {\n"
"\t\t\t\tconst data = await response.text();\n"
"\t\t\t\ttextarea.value = data;\n"
"\t\t\t} else {\n"
"\t\t\t\ttextarea.value = 'Error fetching passwords.';\n"
"\t\t\t}\n"
"\t\t} catch (error) {\n"
"\t\t\tconsole.error('Error fetching passwords:', error);\n"
"\t\t\ttextarea.value = 'Failed to fetch passwords.';\n"
"\t\t}\n"
"\t}\n"
"\tfetchPasswords();\n"
"    </script>\n"
"</body>\n"
"</html>";