//#include <avr/wdt.h>

#define InBaseQuantity 32
#define OutBaseQuantity 32

#define arrayLines 20  //buffer size

int RelayState[16];
int InputState[16];

//for the 74595 and 74165 registre
int DataOutPin = 13;
int DataInPin = 35; 
int ClockPin = 14;
int LatchPin = 15;

int c = 0b0000000000000000;

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

  pinMode(0, OUTPUT);digitalWrite(0, LOW);
  pinMode(DataOutPin, OUTPUT);
  pinMode(ClockPin, OUTPUT);
  pinMode(LatchPin, OUTPUT);
  pinMode(DataInPin, INPUT);
}

void loop() {

  //wdt_reset();

  GetSerialData();

  UseSerialData();
}