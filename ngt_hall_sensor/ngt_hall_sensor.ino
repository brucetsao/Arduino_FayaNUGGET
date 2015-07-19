// Faya-Nugget Sample Code 
// Date: 2015/1/26
// Module Name: Hall Sensor
// Module Number: #ngt-ss-hall-1A
// Description: Determine the magnetic pole of the Hall sensor and show the results in serial monitor.
//              When the north pole of the magnet face to the Hall sensor, it shows N pole.
//              When the south pole of the magnet face to the Hall sensor, it shows S pole.

// Wiring: Module Pin ==> Arduino Pin
//               Vout ==> A0

void setup()
{
  Serial.begin(9600);          //Setup uart baud rate
}


void loop()
{
  int magnet;
  magnet=analogRead(A0);      //Read hall module Vout pin value
  
  Serial.print("Magnetic magnitude= ");        
  Serial.print(magnet);        //Show hall module analog voltage value
  Serial.print("   "); 
  
  if(magnet > 750)            //Magnet N pole
    Serial.print("N pole");  
  else if(magnet < 250)       //Magnet S pole
    Serial.print("S pole");
     
  Serial.println();
  delay(1000);
}
