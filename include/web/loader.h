
const char loader_html[] = 
"<!DOCTYPE html>\n"
"<html lang=\"it\">\n"
"<head>\n"
"    <meta charset=\"UTF-8\">\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"    <style>\n"
"        body {\n"
"            margin: 0;\n"
"            padding: 0;\n"
"            display: flex;\n"
"            align-items: center;\n"
"            justify-content: center;\n"
"            height: 100vh;\n"
"            background-color: #ffffff;\n"
"            font-family: Arial, sans-serif;\n"
"        }\n"
"        .loader {\n"
"            border: 8px solid #f3f3f3;\n"
"            border-top: 8px solid #007bff;\n"
"            border-radius: 50%;\n"
"            width: 10vmin;\n"
"            height: 10vmin;\n"
"            animation: spin 1s linear infinite;\n"
"        }\n"
"        @keyframes spin {\n"
"            0% {\n"
"                transform: rotate(0deg);\n"
"            }\n"
"            100% {\n"
"                transform: rotate(360deg);\n"
"            }\n"
"        }\n"
"        @media (max-width: 768px) {\n"
"            .loader {\n"
"                width: 12vmin;\n"
"                height: 12vmin;\n"
"            }\n"
"        }\n"
"        @media (max-width: 480px) {\n"
"            .loader {\n"
"                width: 15vmin;\n"
"                height: 15vmin;\n"
"            }\n"
"        }\n"
"    </style>\n"
"</head>\n"
"<body>\n"
"    <div class=\"loader\"></div>\n"
"\t<script>setTimeout(function(){window.location.href = \"index.html\";}, 6000);\n"
"    </script>\n"
"</body>\n"
"</html>";