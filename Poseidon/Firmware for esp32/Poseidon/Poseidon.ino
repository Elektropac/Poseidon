#include <avr/wdt.h>

#define InBaseQuantity 32
#define OutBaseQuantity 32

#define arrayLines 20  //buffer size

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
  Serial.begin(9600);  //start with 9600 baud
  Serial.setTimeout(1000);
  wdt_enable(WDTO_8S);
  Serial.println("Setup Completed");  //Serial ready
}

void loop() {

  wdt_reset();

  GetSerialData();

  UseSerialData();
}