void ShiftData()//this function is shifting data in and out
{
  //lacthPin (ST_CP)
  //ClockPin (CP)
  //DataOutPin ()
  //DataInPin ()

  digitalWrite(LoadParallel, LOW);
  delayMicroseconds(5);
  digitalWrite(LoadParallel, HIGH);
  delayMicroseconds(5);
  // digitalWrite(LoadParallel, LOW);
  // delayMicroseconds(5);


  digitalWrite(LatchPin, LOW);

  for (int i=1; i<17; i++) 
  {
    digitalWrite(DataOutPin, bitRead(c, i) );
    //InputState[i] = digitalRead(DataInPin);
    digitalWrite(ClockPin, HIGH);delayMicroseconds(10);
    digitalWrite(ClockPin, LOW);delayMicroseconds(10);
    //Serial.print(InputState[i]);Serial.print(",");

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