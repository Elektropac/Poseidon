/*This is code for the realy board
  18/08/2022
  by Jesper Møller
*/



#include <Wire.h>

//#define Relay1 
//#define Relay2 
//#define Relay3 
//#define Relay4 
//#define Relay5 
//#define Relay6 
//#define Relay7 
//#define Relay8 
//#define Relay9  
//#define Relay10  
//#define Relay11 
//#define Relay12 
//#define Relay13  
//#define Relay14  
//#define Relay15 
//#define Relay16 
//
//#define Input1
//#define Input2
//#define Input3
//#define Input4
//#define Input5
//#define Input6
//#define Input7
//#define Input8
//#define Input9
//#define Input10
//#define Input11
//#define Input12
//#define Input13
//#define Input14
//#define Input15
//#define Input16




int dataRegister[100];//this is for in and outputs
int dataRegisterPointer;



void setup() // put your setup code here, to run once:
{
  Serial.begin(115200);
  Wire.begin();
  
}

void loop() // put your main code here, to run repeatedly:
{
  //is there new data

  //check and update inputs

}
