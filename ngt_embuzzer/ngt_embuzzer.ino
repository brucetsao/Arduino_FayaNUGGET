// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: Electromagnetic Buzzer
// Module Number: #ngt-mm-embuzr-1A
// Description:Use Serial-Monutor to control Electromagnetic Buzzer.

// Wiring: Module Pin ==> Arduino Pin
//                 BZ ==> D11


// define pins
#define EmBuz 11

void setup() 
{ 
  //setup uart baud rate.
  Serial.begin(9600); 
  pinMode(EmBuz, OUTPUT); 
  
  Serial.println("Please enter number:");
  Serial.println("Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Si=7");
}

char ch=0;

void loop()
{

    // send data only when you receive data:
    if (Serial.available() > 0)
    {
        // read the Data:
         ch = Serial.read();
    }
        
    switch(ch)  
    {
      case '1':      //Diatonic scale Do
         tone(EmBuz,262);
         delay(500); 
         break;
      case '2':      //Diatonic scale Re
         tone(EmBuz,294);
         delay(500); 
         break;
      case '3':      //Diatonic scale Mi
         tone(EmBuz,330);
         delay(500); 
         break;
      case '4':      //Diatonic scale Fa
         tone(EmBuz,349);
         delay(500); 
         break;
      case '5':      //Diatonic scale So
         tone(EmBuz,392);
         delay(500); 
         break;
      case '6':      //Diatonic scale La
         tone(EmBuz,440);
         delay(500); 
         break;
      case '7':      //Diatonic scale Si
         tone(EmBuz,494);
         delay(500); 
         break;        
    }
    
    noTone(EmBuz);
    ch=0;
}


