void ShiftData()//this function is shifting data in and out
{
  //lacthPin (ST_CP)
  //ClockPin (CP)
  //DataOutPin ()
  //DataInPin ()

  //digitalWrite(LoadParallel, LOW);
  //delayMicroseconds(5);
  digitalWrite(LoadParallel, LOW);
  //delayMicroseconds(5);
  // digitalWrite(LoadParallel, LOW);
  // delayMicroseconds(5);
//Sequense for serial out: 1 Latch low, 2 set dataoutpin, 3 Clock pin HIGH the LOW, 4 Latch High

  digitalWrite(LatchPin, LOW);

  for (int i=1; i<17; i++) 
  {
    digitalWrite(DataOutPin, bitRead(c, i) );
    //InputState[i] = digitalRead(DataInPin);
    digitalWrite(ClockPin, HIGH);delayMicroseconds(10);
    digitalWrite(ClockPin, LOW);delayMicroseconds(10);
    //Serial.print(InputState[i]);Serial.print(",");
    //shiftOut(DataOPutPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)

  }

  digitalWrite(LatchPin, HIGH); //(ST_CP)
  
  SerialprintState();
}

//InputState

void SerialprintState()
{
  
  {
    Serial.print("RelayState:");
    for (int i = 1 ; i < 17 ; i++ )
    {
      Serial.print(RelayState[i]);
    }
    
    Serial.print(" - ");

    Serial.print("InputState:");
    for (int i = 1 ; i < 17 ; i++ )
    {
      Serial.print(InputState[i]);
    }
    Serial.println();

  }
}