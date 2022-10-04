//#include <avr/wdt.h>
#include <WiFi.h>
#include <WebServer.h>

/* Put your SSID & Password */
const char* ssid = "MCScontrol";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

int Update = 1;



#define InBaseQuantity 32
#define OutBaseQuantity 32

#define arrayLines 20  //buffer size

int RelayState[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int InputState[20]={0,1,0,1,0,1,0,1,1,0,0,1,1,0,0,1,0};

//for the 74595 and 74165 registre
int DataOutPin = 13;
int DataInPin = 35; 
int ClockPin = 14;
int LatchPin = 15;
int LoadParallel = 0;

int c = 0b1111111111111111;

int Address;   //this is for the I2C address 1-9 is for base 10-100 is for cells
int Function;  //which function to run

String InBaseStr[InBaseQuantity + 4];  //In data array
uint16_t InBase[InBaseQuantity];       //In data array
uint16_t OutBase[OutBaseQuantity];     //Out data array

String NewData[arrayLines];  //string buffer for new serial data
int Acount = 0;
int Bcount = 0;
int Ccount = 0;


void setup() {
  Serial.begin(115200);  //start with 9600 baud
  //Serial.setTimeout(1000);
  //wdt_enable(WDTO_8S);
  Serial.println("Setup Completed");  //Serial ready

  pinMode(LoadParallel, OUTPUT);digitalWrite(LoadParallel, HIGH);
  pinMode(DataOutPin, OUTPUT);
  pinMode(ClockPin, OUTPUT);
  pinMode(LatchPin, OUTPUT);
  pinMode(DataInPin, INPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  setupHandler();
  SetRelayNow();

}

void loop() {

  //wdt_reset();

  GetSerialData();

  UseSerialData();

  server.handleClient();
}