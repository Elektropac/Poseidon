
//#include <avr/wdt.h>
#include "SerialFunctions.h"

int Function = 0;
#define InBaseQuantity 32
#define OutBaseQuantity 32



String InBaseStr[InBaseQuantity+4];//In data array

uint16_t InBase[InBaseQuantity];//In data array
uint16_t OutBase[OutBaseQuantity];//Out data array


#define arrayLines 10 //buffer size
String NewData[arrayLines];//string buffer for new serial data
int Acount = 0;
int Bcount = 0;
int Ccount = 0;


void serialDataHandler();
void UseNewSerialData();
void checkForNewSerialData();



void setup() 
{

  Serial.begin(9600);//start with 9600 baud
  Serial.setTimeout(1000);
  //wdt_enable(WDTO_8S);
}

void loop() 
{
 // wdt_reset();
  

  checkForNewSerialData();

  UseNewSerialData();
  

}




  

  
}

