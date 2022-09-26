
void serialDataHandler()
{
  switch (Function) 
  {
    case 0:
      break;
      
    case 1:
      break;
      
    case 2:
      break;

    case 3:
      break;      
      
    case 4:
      break;      

    case 5:
      break;  

    case 6:
      break;  

    case 7:
      break;  

    case 8:
      break;  

    case 9:
      break;  

    case 10:
      break;


    
    default:
      Serial.println("Error in dataType. ");Serial.println(Function);
      break;
  }
}

void checkForNewSerialData()
{
  if (Serial.available()>0)//hvis der er noget klar på serialporten
  {
    NewData[Acount] = Serial.readStringUntil('\n');//læs indtil der er en newline 
    Acount++;//tæl Acount op med 1
    if (Acount >= arrayLines)//hvis vi har talt op til over den angivne mængde linjer så start for fra
    {
      Acount = 0;//Acount nul stilles
    }
    Ccount++;//vi tæller Ccount op med 1 for at indikere at der er nyt data klar til brug
  }

  if (Ccount >= arrayLines)//check if there is to much data
  {
    Serial.println("Serial overflow:");
  }
  return;
}

void UseNewSerialData()
{
  //Use serial data
  if ((Ccount>0) and (Serial.available()<1))//if there is new data to be used and the serail port is not full/ready then use data
  {  
    int arrayNr = 0;
    for (int i = 0; i<12; i++)//erase old data
    {
      InBaseStr[i] = "";
    }
      
    for (int i = 0 ; i < NewData[Bcount].length() ; i++ )
    {
      if (NewData[Bcount].charAt(i) == ',')//hvis den næste char er vores sepperator
      {
        arrayNr++; //dette for at gøre klar til at skrive til den næste plades i dette array
        i++;//dette er for at passerer  sepperatoren
      }
      InBaseStr[arrayNr] += NewData[Bcount].charAt(i); //skriv data til array
    }
      
    
    Function = InBaseStr[1].toInt();


    //her laver vi vores string om til int
    for (int i = 0 ; i < InBaseQuantity ; i++)
    {
      InBase[i] = InBaseStr[i+3].toInt();//de første 2 pladser springes over
    }
        
    serialDataHandler();//denne funktion bruger den data vi lige har lavet
    
    Bcount++;//vi tæller Bcount op med 1
    if (Bcount >= arrayLines)//hvis Bcount er over angivede mængde så null stil
    {
      Bcount = 0;
    }
    Ccount--;//et sæt data er brugt og vi nedskriver Ccount med 1
  }

