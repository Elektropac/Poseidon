
void handle_OnConnect() 
{
  server.send(200, "text/html", SendHTML()); 
}


void handle_NotFound()
{
  server.send(404, "text/plain", "Not found");
}

  
void setupHandler()
  {
  server.on("/start", handle_OnConnect);

  server.on("/Update", handle_Update);

  server.on("/relay1on", handle_relay1on);
  server.on("/relay1off", handle_relay1off);

  server.on("/relay2on", handle_relay2on);
  server.on("/relay2off", handle_relay2off);

  server.on("/relay3on", handle_relay3on);
  server.on("/relay3off", handle_relay3off);

  server.on("/relay4on", handle_relay4on);
  server.on("/relay4off", handle_relay4off);

  server.on("/relay5on", handle_relay5on);
  server.on("/relay5off", handle_relay5off);

  server.on("/relay6on", handle_relay6on);
  server.on("/relay6off", handle_relay6off);

  server.on("/relay7on", handle_relay7on);
  server.on("/relay7off", handle_relay7off);
  
  server.on("/relay8on", handle_relay8on);
  server.on("/relay8off", handle_relay8off);

  server.on("/relay9on", handle_relay9on);
  server.on("/relay9off", handle_relay9off);

  server.on("/relay10on", handle_relay10on);
  server.on("/relay10off", handle_relay10off);
  
  server.on("/relay11on", handle_relay11on);
  server.on("/relay11off", handle_relay11off);

  server.on("/relay12on", handle_relay12on);
  server.on("/relay12off", handle_relay12off);

  server.on("/relay13on", handle_relay13on);
  server.on("/relay13off", handle_relay13off);

  server.on("/relay14on", handle_relay14on);
  server.on("/relay14off", handle_relay14off);

  server.on("/relay15on", handle_relay15on);
  server.on("/relay15off", handle_relay15off);

  server.on("/relay16on", handle_relay16on);
  server.on("/relay16off", handle_relay16off);


  server.onNotFound(handle_NotFound);
  
  server.begin();
}



String SendHTML()
{
 
  SetRelayNow();
  
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head>\n";
  ptr += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n";




  ptr += "<meta http-equiv=\"refresh\" content=\"3; /Update\"/>\n";





  ptr += "<title>MCS CONTROL SYSTEM</title>\n";
  


 

  ptr += "<style>\n"; 



 ptr+= "body { color: white; background-color: #34568b;}\n";

  ptr += "html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";

  ptr += "body{margin-top: 50px;} h1 {color: #FFFFFF;margin: 50px 30px;} h3 {color: #FFFFFF;margin-bottom: 50px;}\n";
  
  ptr +=".button {display:block;width: 100px;background-color: #3498db;border: none;color: white;padding: 20px 10px;text-decoration: none;font-size: 20px;margin: 10px auto 10px;cursor: pointer;border-radius: 12px;}\n";
  

  
  ptr += ".button-on {background-color: #3DB03C;}\n";
  ptr += ".button-on:active {background-color: #2980b9;}\n";
  
  ptr += ".button-off {background-color: #DB4541;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";

  ptr += ".button-OPEN {background-color: #1896C3;}\n";
  //ptr += ".button-:active {background-color: #2980b9;}\n";
  
  ptr += ".button-CLOSED {background-color: #C34F22;}\n";
  //ptr += ".button-offA:active {background-color: #2c3e50;}\n";
  
  
  
  ptr += "p {font-size: 16px;color: white;margin-bottom: 10px;}\n";
  
  ptr += "table {width: 100%;}\n";
  ptr += "td{text-align: center;}\n";

  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  

// _/ _ NO

// _ \_ NC   NC<COM NO

  ptr +="<h1>OUTPUTS:</h1>\n";




ptr +="<table>\n";
ptr +="<tr>\n";

   if(RelayState[1]>0)
  {ptr +="<th><p>Relay 1</p><a class=\"button button-off\" href=\"/relay1off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 1</p><a class=\"button button-on\" href=\"/relay1on\">COM-NC</a></th>\n";}

 
    if(RelayState[2]>0)
  {ptr +="<th><p>Relay 2</p><a class=\"button button-off\" href=\"/relay2off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 2</p><a class=\"button button-on\" href=\"/relay2on\">COM-NC</a></th>\n";}


   if(RelayState[3]>0)
  {ptr +="<th><p>Relay 3</p><a class=\"button button-off\" href=\"/relay3off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 3</p><a class=\"button button-on\" href=\"/relay3on\">COM-NC</a></th>\n";}


   if(RelayState[4]>0)
  {ptr +="<th><p>Relay 4</p><a class=\"button button-off\" href=\"/relay4off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 4</p><a class=\"button button-on\" href=\"/relay4on\">COM-NC</a></th>\n";}

 
// ptr +="</tr>"; 

// ptr +="<tr>";

   if(RelayState[5]>0)
  {ptr +="<th><p>Relay 5</p><a class=\"button button-off\" href=\"/relay5off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 5</p><a class=\"button button-on\" href=\"/relay5on\">COM-NC</a></th>\n";}


   if(RelayState[6]>0)
  {ptr +="<th><p>Relay 6</p><a class=\"button button-off\" href=\"/relay6off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 6</p><a class=\"button button-on\" href=\"/relay6on\">COM-NC</a></th>\n";}


   if(RelayState[7]>0)
  {ptr +="<th><p>Relay 7</p><a class=\"button button-off\" href=\"/relay7off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 7</p><a class=\"button button-on\" href=\"/relay7on\">COM-NC</a></th>\n";}


   if(RelayState[8]>0)
  {ptr +="<th><p>Relay 8</p><a class=\"button button-off\" href=\"/relay8off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 8</p><a class=\"button button-on\" href=\"/relay8on\">COM-NC</a></th>\n";}

 
ptr +="</tr>\n"; 

ptr +="<tr>\n";

   if(RelayState[9]>0)
  {ptr +="<th><p>Relay 9</p><a class=\"button button-off\" href=\"/relay9off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 9</p><a class=\"button button-on\" href=\"/relay9on\">COM-NC</a></th>\n";}


   if(RelayState[10]>0)
  {ptr +="<th><p>Relay 10</p><a class=\"button button-off\" href=\"/relay10off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 10</p><a class=\"button button-on\" href=\"/relay10on\">COM-NC</a></th>\n";}


   if(RelayState[11]>0)
  {ptr +="<th><p>Relay 11</p><a class=\"button button-off\" href=\"/relay11off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 11</p><a class=\"button button-on\" href=\"/relay11on\">COM-NC</a></th>\n";}


   if(RelayState[12]>0)
  {ptr +="<th><p>Relay 12</p><a class=\"button button-off\" href=\"/relay12off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 12</p><a class=\"button button-on\" href=\"/relay12on\">COM-NC</a></th>\n";}

 
// ptr +="</tr>"; 

// ptr +="<tr>";

   if(RelayState[13]>0)
  {ptr +="<th><p>Relay 13</p><a class=\"button button-off\" href=\"/relay13off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 13</p><a class=\"button button-on\" href=\"/relay13on\">COM-NC</a></th>\n";}


   if(RelayState[14]>0)
  {ptr +="<th><p>Relay 14</p><a class=\"button button-off\" href=\"/relay14off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 14</p><a class=\"button button-on\" href=\"/relay14on\">COM-NC</a></th>\n";}


   if(RelayState[15]>0)
  {ptr +="<th><p>Relay 15</p><a class=\"button button-off\" href=\"/relay15off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 15</p><a class=\"button button-on\" href=\"/relay15on\">COM-NC</a></th>\n";}


   if(RelayState[16]>0)
  {ptr +="<th><p>Relay 16</p><a class=\"button button-off\" href=\"/relay16off\">NO-COM</a></th>\n";}
  else
  {ptr +="<th><p>Relay 16</p><a class=\"button button-on\" href=\"/relay16on\">COM-NC</a></th>\n";}

 
ptr +="</tr>\n"; 
ptr +="</table>\n"; 

 ptr +="<h1>INPUTS:</h1>\n";

 ptr +="<table>";


ptr +="<tr>";

   if(InputState[1]==0)
  {ptr +="<th><p>Input 1</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 1</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[2]==0)
  {ptr +="<th><p>Input 2</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 2</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[3]==0)
  {ptr +="<th><p>Input 3</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 3</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[4]==0)
  {ptr +="<th><p>Input 4</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 4</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}

 
// ptr +="</tr>"; 

// ptr +="<tr>";

   if(InputState[5]==0)
  {ptr +="<th><p>Input 5</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 5</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[6]==0)
  {ptr +="<th><p>Input 6</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 6</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[7]==0)
  {ptr +="<th><p>Input 7</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 7</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[8]==0)
  {ptr +="<th><p>Input 8</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 8</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}

 
ptr +="</tr>"; 

ptr +="<tr>";

   if(InputState[9]==0)
  {ptr +="<th><p>Input 9</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 9</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[10]==0)
  {ptr +="<th><p>Input 10</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 10</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[11]==0)
  {ptr +="<th><p>Input 11</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 11</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[12]==0)
  {ptr +="<th><p>Input 12</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 12</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}

 
// ptr +="</tr>"; 

// ptr +="<tr>";

   if(InputState[13]==0)
  {ptr +="<th><p>Input 13</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 13</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[14]==0)
  {ptr +="<th><p>Input 14</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 14</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[15]==0)
  {ptr +="<th><p>Input 15</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 15</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}


   if(InputState[16]==0)
  {ptr +="<th><p>Input 16</p><a class=\"button button-OPEN\" href=\"/Update\">OPEN</a></th>";}
  else
  {ptr +="<th><p>Input 16</p><a class=\"button button-CLOSED\" href=\"/Update\">CLOSED</a></th>";}

 
ptr +="</tr>"; 
ptr +="</table>"; 



  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}




void handle_Update() 
{ server.send(200, "text/html", SendHTML()); }


void handle_relay1on() 
{ RelayState[1] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay1off() 
{ RelayState[1] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay2on() 
{ RelayState[2] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay2off() 
{ RelayState[2] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay3on() 
{ RelayState[3] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay3off() 
{ RelayState[3] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay4on() 
{ RelayState[4] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay4off() 
{ RelayState[4] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay5on() 
{ RelayState[5] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay5off() 
{ RelayState[5] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay6on() 
{ RelayState[6] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay6off() 
{ RelayState[6] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay7on() 
{ RelayState[7] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay7off() 
{ RelayState[7] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay8on() 
{ RelayState[8] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay8off() 
{ RelayState[8] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay9on() 
{ RelayState[9] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay9off() 
{ RelayState[9] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay10on() 
{ RelayState[10] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay10off() 
{ RelayState[10] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay11on() 
{ RelayState[11] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay11off() 
{ RelayState[11] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay12on() 
{ RelayState[12] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay12off() 
{ RelayState[12] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay13on() 
{ RelayState[13] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay13off() 
{ RelayState[13] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay14on() 
{ RelayState[14] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay14off() 
{ RelayState[14] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay15on() 
{ RelayState[15] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay15off() 
{ RelayState[15] = 0; server.send(200, "text/html", SendHTML()); }


void handle_relay16on() 
{ RelayState[16] = 1; server.send(200, "text/html", SendHTML()); }

void handle_relay16off() 
{ RelayState[16] = 0; server.send(200, "text/html", SendHTML()); }


