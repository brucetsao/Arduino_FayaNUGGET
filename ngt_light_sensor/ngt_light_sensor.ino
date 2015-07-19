// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: Light Sensor
// Module Number: #ngt-ss-cds-1A
// Description: Detect light maginitude and show the result in serial monitor.  

// Wiring: Module Pin ==> Arduino Pin
//               Vout ==> A0

void setup()
{
    Serial.begin(9600);            //setup uart baud rate
}

void loop()
{
    int cds;
    cds=analogRead(A0);           //read A0 pin value in the cds.
    Serial.print("Brightness: ");
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
    
    delay(500);
}
