
#include <WiFiManager.h> 

#define SetFactory 0

// wifimanager can run in a blocking mode or a non blocking mode
// Be sure to know how to process loops with no delay() if using non blocking
bool wm_nonblocking = false; // change to true to use non blocking

WiFiManager wm; // global wm instance
WiFiManagerParameter custom_field; // global param ( for non blocking w params )

void setup() 
{
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP  
  Serial.begin(115200);
  Serial.setDebugOutput(true);  
  delay(3000);
  Serial.println("\n Starting");

  pinMode(SetFactory, INPUT);


  if(wm_nonblocking) wm.setConfigPortalBlocking(false);
  int customFieldLength = 40;// add a custom input field
  const char* custom_radio_str = "<br/><label for='customfieldid'>Custom Field Label</label><input type='radio' name='customfieldid' value='1' checked> One<br><input type='radio' name='customfieldid' value='2'> Two<br><input type='radio' name='customfieldid' value='3'> Three";
  new (&custom_field) WiFiManagerParameter(custom_radio_str); // custom html input
  wm.addParameter(&custom_field);
  wm.setSaveParamsCallback(saveParamCallback);
  std::vector<const char *> menu = {"wifi","info","param","sep","restart","exit"};
  wm.setMenu(menu);
  wm.setClass("invert");// set dark theme
  wm.setConfigPortalTimeout(30); // auto close configportal after n seconds

  bool res;
  res = wm.autoConnect("MCSConnect"); // password protected ap
  if(!res){Serial.println("Failed to connect or hit timeout"); ESP.restart();} 
  else{Serial.println("connected to wifi");}//if you get here you have connected to the WiFi 
}






void loop() 
{
  if(wm_nonblocking) wm.process(); // avoid delays() in loop when non-blocking and other long running code  
  checkButton();
}
