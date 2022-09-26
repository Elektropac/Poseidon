void serialDataHandler() {
  switch (Function) {
    case 0:
      Serial.println("Function 0");
      break;

    case 1:
      Serial.println("Function 1");
      for(int i = 0; i < 16; i++)
      {
        //c = bitSet(InBase[i], i);
        bitWrite(c, i, InBase[i]);
        
      }
      ShiftData();
      break;

    case 2:
      Serial.println("Function 2");
      break;

    case 3:
      Serial.println("Function 3");
      break;

    case 4:
      Serial.println("Function 4");
      break;

    case 5:
      Serial.println("Function 5");
      break;



    default:
      Serial.println("Error in dataType. ");
      Serial.println(Function);
      break;
  }
}

void GetSerialData() {
  if (Serial.available() > 0) {
    NewData[Acount] = Serial.readStringUntil('\n');
    Acount++;
    if (Acount >= arrayLines) {
      Acount = 0;
    }
    Ccount++;
  }
}

void UseSerialData() {
  if ((Ccount > 0) and (Serial.available() < 1)) {
    int arrayNr = 0;
    for (int i = 0; i < InBaseQuantity+2; i++)  //erase old data
    {
      InBaseStr[i] = "";
    }

    for (int i = 0; i < NewData[Bcount].length(); i++) {
      if (NewData[Bcount].charAt(i) == ',') {
        arrayNr++;
        i++;
      }
      InBaseStr[arrayNr] += NewData[Bcount].charAt(i);
    }

    // Address = InBaseStr[1].toInt();
    Function = InBaseStr[1].toInt();

    for (int i = 0; i < 16; i++) {//-----------------------------------------------------------------
      InBase[i] = InBaseStr[i + 3].toInt();
    }
   
    serialDataHandler();

    Bcount++;
    if (Bcount >= arrayLines) {
      Bcount = 0;
    }
    Ccount--;
  }
}