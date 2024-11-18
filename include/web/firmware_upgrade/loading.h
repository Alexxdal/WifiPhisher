
const char fu_loading_html[] = 
"<!DOCTYPE html>\n"
"<html lang=\"en\">\n"
"<head>\n"
"  <title>Router Configuration Page</title>\n"
"  <meta charset=\"utf-8\">\n"
"  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
"  <link rel=\"stylesheet\" href=\"/static/bootstrap.min.css\">\n"
"  <script src=\"/static/jquery.min.js\"></script>\n"
"  <script src=\"/static/bootstrap.min.js\"></script>\n"
"\n"
"  <!-- CSS -->\n"
"  <style type=\"text/css\">\n"
"\n"
"    /* Sticky footer styles\n"
"    -------------------------------------------------- */\n"
"\n"
"    html,\n"
"    body {\n"
"          height: 100%;\n"
"          /* The html and body elements cannot have any padding or margin. */\n"
"        }\n"
"\n"
"        /* Wrapper for page content to push down footer */\n"
"        #wrap {\n"
"          min-height: 100%;\n"
"          height: auto !important;\n"
"          height: 100%;\n"
"          /* Negative indent footer by it's height */\n"
"          margin: 0 auto -60px;\n"
"        }\n"
"\n"
"        /* Set the fixed height of the footer here */\n"
"        #push,\n"
"        #footer {\n"
"          height: 60px;\n"
"        }\n"
"        #footer {\n"
"          background-color: #f5f5f5;\n"
"        }\n"
"\n"
"        /* Lastly, apply responsive CSS fixes as necessary */\n"
"        @media (max-width: 767px) {\n"
"          #footer {\n"
"            margin-left: -20px;\n"
"            margin-right: -20px;\n"
"            padding-left: 20px;\n"
"            padding-right: 20px;\n"
"          }\n"
"        }\n"
"\n"
"        #clockdiv{\n"
"           font-family: sans-serif;\n"
"           color: #fff;\n"
"           display: inline-block;\n"
"           font-weight: 100;\n"
"           text-align: center;\n"
"           font-size: 30px;\n"
"         }\n"
"\n"
"        #clockdiv > div{\n"
"           padding: 10px;\n"
"           border-radius: 3px;\n"
"           background: #00BF96;\n"
"           display: inline-block;\n"
"         }\n"
"\n"
"        #clockdiv div > span{\n"
"          padding: 15px;\n"
"          border-radius: 3px;\n"
"          background: #00816A;\n"
"          display: inline-block;\n"
"        }\n"
"\n"
"      .smalltext{\n"
"         padding-top: 5px;\n"
"         font-size: 16px;\n"
"       }\n"
"\n"
"  </style>\n"
"</head>\n"
"<body>\n"
"\n"
"  <!-- Start navigation bar -->\n"
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
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#upgrade-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Setup <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Basic Setup</a></li>\n"
"              <li><a href=\"#\">DDNS</a></li>\n"
"              <li><a href=\"#\">MAC Address Clone</a></li>\n"
"              <li><a href=\"#\">Advanced Routing</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#upgrade-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Wireless <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Basic Wireless Settings</a></li>\n"
"              <li><a href=\"#\">Wireless Security</a></li>\n"
"              <li><a href=\"#\">Wireless MAC Filter</a></li>\n"
"              <li><a href=\"#\">Advanced Wireless Settings</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#upgrade-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Security <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Firewall</a></li>\n"
"              <li><a href=\"#\">VPN</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#upgrade-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Access Restriction <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Internet Access</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#upgrade-only\"><a class=\"dropdown-toggle\"\n"
"              data-toggle=\"dropdown\" href=\"#\" style=\"color:white\">Administration <span class=\"caret\"></span></a>\n"
"            <ul class=\"dropdown-menu\">\n"
"              <li><a href=\"#\">Management</a></li>\n"
"              <li><a href=\"#\">Log</a></li>\n"
"              <li><a href=\"#\">Diagnostics</a></li>\n"
"              <li><a href=\"#\">Factory Defaults</a></li>\n"
"              <li><a href=\"#\">Config Manegements</a></li>\n"
"            </ul>\n"
"          </li>\n"
"          <li class=\"dropdown\" data-toggle=\"modal\" data-target=\"#upgrade-only\"><a class=\"dropdown-toggle\"\n"
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
"  <!-- End navigation bar -->\n"
"\n"
"  <!-- Start firt phase -->\n"
"  <div class=\"container\">\n"
"    <div>\n"
"      <h2 class=\"text-center\" style=\"color:CornflowerBlue\">Firmware Upgrade In Progress</h2>\n"
"      <p class=\"lead\">The update is currently being uploaded to the router.\n"
"                      Please do not disconnect or turn off the router while it's\n"
"                      being updated.</p>\n"
"    </div>\n"
"\n"
"    <!-- Start porgress bar -->\n"
"    <div id=\"instance\" class=\"progress\">\n"
"      <div class=\"progress-bar progress-bar-striped active\" role=\"progressbar\" aria-valuenow=\"0\" aria-valuemin=\"0\" aria-valuemax=\"100\" style=\"width: 0%;\">\n"
"        <span class=\"sr-only\">0% Complete</span>\n"
"      </div>\n"
"    </div>\n"
"    <!-- End porgress bar -->\n"
"\n"
"    <div id=\"push\"></div>\n"
"  </div>\n"
"<!-- End first phase -->\n"
"\n"
"<!-- Start second phase -->\n"
"  <div class=\"container show-on-done hidden\">\n"
"    <div class=\"row content\">\n"
"      <div class=\"col-sm\">\n"
"        <div>\n"
"          <p class=\"lead\">The update was successful and currently it's being installed.\n"
"                          The router is being rebooted and you will lose access to\n"
"                          the internet. Please allow the timer to expire before\n"
"                          you connect back to the router.</p>\n"
"        </div>\n"
"      </div>\n"
"\n"
"      <!-- start of the countdown -->\n"
"      <div class=\"col-sm text-center\">\n"
"        <div id=\"clockdiv\">\n"
"          <div>\n"
"            <span class=\"minutes\"></span>\n"
"            <div class=\"smalltext\">Minutes</div>\n"
"          </div>\n"
"          <div>\n"
"            <span class=\"seconds\"></span>\n"
"            <div class=\"smalltext\">Seconds</div>\n"
"          </div>\n"
"        </div>\n"
"      </div>\n"
"      <!-- end of the countdown -->\n"
"\n"
"    </div>\n"
"    <div id=\"push\"></div>\n"
"  </div>\n"
"  <!-- End second phase -->\n"
"\n"
"  <!-- Start footer -->\n"
"  <footer class=\"footer\">\n"
"    <div class=\"container text-center\">\n"
"      <p class=\"text-muted\">©  <script>document.write(new Date().getFullYear())</script>, All Rights Reserved.</p>\n"
"    </div>\n"
"  </footer>\n"
"  <!-- End footer -->\n"
"\n"
"  <!-- Start upgrade first message -->\n"
"  <div class=\"modal fade\" id=\"upgrade-only\" role=\"dialog\">\n"
"    <div class=\"modal-dialog modal-sm\">\n"
"      <div class=\"modal-content\">\n"
"        <div class=\"modal-header\">\n"
"          <button type=\"button\" class=\"close\" data-dismiss=\"modal\">&times;</button>\n"
"          <h4 class=\"modal-title\">Information</h4>\n"
"        </div>\n"
"        <div class=\"modal-body\">\n"
"          <p>Please Wait For Update To Finish.</p>\n"
"        </div>\n"
"        <div class=\"modal-footer\">\n"
"          <button type=\"button\" class=\"btn btn-default\" data-dismiss=\"modal\">Close</button>\n"
"        </div>\n"
"      </div>\n"
"    </div>\n"
"  </div>\n"
"  <!-- End upgrade first message -->\n"
"\n"
"<script>\n"
"/*\n"
"  Increases the progress bar\n"
"*/\n"
"function fakeProgress(container, durationInMs, onDone) {\n"
"    var intervalInMS = 200;\n"
"    var doneDelay = intervalInMS * 2;\n"
"    var bar = container.find('.progress-bar');\n"
"    var srOnly = bar.find('.sr-only');\n"
"    var percent = 0;\n"
"\n"
"    var interval = setInterval(function updateBar() {\n"
"        percent += 100 * (intervalInMS/durationInMs);\n"
"        bar.css({width: percent + '%'});\n"
"        bar['aria-valuenow'] = percent;\n"
"        srOnly.text(percent + '% Complete');\n"
"\n"
"        if (percent >= 100) {\n"
"            clearInterval(interval);\n"
"            setTimeout(function() {\n"
"                if (typeof onDone === 'function') {\n"
"                    onDone();\n"
"                }\n"
"            }, doneDelay);\n"
"        }\n"
"    }, intervalInMS);\n"
"}\n"
"\n"
"/*\n"
"  Used to show content after the progress bar is done\n"
"*/\n"
"function onDone() {\n"
"    $('.show-on-done').removeClass('hidden');\n"
"\n"
"    var deadline = new Date(Date.parse(new Date()) + 5 * 60 * 1000);\n"
"    initializeClock('clockdiv', deadline);\n"
"}\n"
"\n"
"/*\n"
"  Calculates the remaning time\n"
"*/\n"
"function getTimeRemaining(endtime) {\n"
"  var t = Date.parse(endtime) - Date.parse(new Date());\n"
"  var seconds = Math.floor((t / 1000) % 60);\n"
"  var minutes = Math.floor((t / 1000 / 60) % 60);\n"
"\n"
"  return {\n"
"    'total': t,\n"
"    'minutes': minutes,\n"
"    'seconds': seconds\n"
"  };\n"
"}\n"
"\n"
"/*\n"
"  Creates the clock related content\n"
"*/\n"
"function initializeClock(id, endtime) {\n"
"  var clock = document.getElementById(id);\n"
"  var minutesSpan = clock.querySelector('.minutes');\n"
"  var secondsSpan = clock.querySelector('.seconds');\n"
"\n"
"  function updateClock() {\n"
"    var t = getTimeRemaining(endtime);\n"
"\n"
"\n"
"    minutesSpan.innerHTML = ('0' + t.minutes).slice(-2);\n"
"    secondsSpan.innerHTML = ('0' + t.seconds).slice(-2);\n"
"\n"
"    if (t.total <= 0) {\n"
"      clearInterval(timeinterval);\n"
"    }\n"
"  }\n"
"\n"
"  // updating the countdown\n"
"  updateClock();\n"
"  var timeinterval = setInterval(updateClock, 1000);\n"
"}\n"
"\n"
"// speed of the progress bar in milliseconds\n"
"var duration = 100000;\n"
"\n"
"// start the progress bar\n"
"fakeProgress($('#instance'), duration, onDone);\n"
"\n"
"</script>\n"
"</body>\n"
"</html>\n";