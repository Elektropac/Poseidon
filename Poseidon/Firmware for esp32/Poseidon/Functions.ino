void ShiftData()//this function is shifting data in and out
{
  //lacthPin (ST_CP)
  //ClockPin (CP)
  //DataOutPin ()
  //DataInPin ()

    

  digitalWrite(LatchPin, LOW);

  for (int i=0; i<16; i++) 
  {
    digitalWrite(DataOutPin, bitRead(c, i) );
    InputState[i] = digitalRead(DataInPin);
    digitalWrite(ClockPin, HIGH);delayMicroseconds(10);
    digitalWrite(ClockPin, LOW);delayMicroseconds(10);
    Serial.print(InputState[i]);Serial.print(",");

  }

  digitalWrite(LatchPin, HIGH); //(ST_CP)
  Serial.println();

}