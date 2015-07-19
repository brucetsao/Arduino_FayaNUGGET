// Wiring: Module Pin ==> Arduino Pin
//               Vout ==> A0
#define LedPin 3

void setup()
{
 //   pinMode(LedPin,OUTPUT);
    Serial.begin(9600);            //setup uart baud rate
}

void loop()
{
    int cds;
    cds=analogRead(A0);           //read A0 pin value in the cds.
    analogWrite(LedPin,255-(cds/4)) ;
    Serial.print("Brightness:( ");
    Serial.print(cds);
    Serial.print("):");
    switch(cds/100)
    {
       case 10:
           Serial.println("* * * * * * * * * *");
           break;
       case 9:
           Serial.println("* * * * * * * * *");
           break;
       case 8:
           Serial.println("* * * * * * * *");
           break;
       case 7:
           Serial.println("* * * * * * *");
           break;   
       case 6:
           Serial.println("* * * * * *");
           break;   
       case 5:
           Serial.println("* * * * *");
           break;    
       case 4:
           Serial.println("* * * *");
           break;  
       case 3:
           Serial.println("* * *");
           break;  
       case 2:
           Serial.println("* *");
           break;  
       case 1:
           Serial.println("*");
           break;      
    }
    
    delay(100);
}
