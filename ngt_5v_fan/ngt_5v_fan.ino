// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name:5V DC Fan
// Module Number: #ngt-mt-fan5v-1A
// Description: Use serial monitor to turn ON/OFF of the fan.

// Wiring: Module Pin ==> Arduino Pin
//                SIG ==> D2


// define pins
#define SIG 2

void setup()
{
  //setup uart baud rate.
  Serial.begin(9600);
  pinMode(SIG, OUTPUT);
  Serial.println("Please enter ON / OFF to turn control the fan. ");
}



void loop()
{
   String onoff="";
 
  // send data only when you receive data:
    while (Serial.available() > 0)
    {
        // read and write the Data:
         onoff += (char) Serial.read(); //read string
         delay(5); // delay 5 ms so next char got time to be reveied
         
         if(onoff == "ON" || onoff == "On" || onoff == "on")
         {
         digitalWrite(SIG,HIGH);
         } 
         
         else if(onoff == "OFF" || onoff == "Off" || onoff == "off")
         {
         digitalWrite(SIG,LOW);
         }          
     
    }
 
}



