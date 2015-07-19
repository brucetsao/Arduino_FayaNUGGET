// Faya-Nugget Sample Code 
// Date: 2015/1/26
// Module Name: Reed Switch
// Module Number: #ngt-ss-rdswtch-1A
// Description: Show the status of reed switch in serial monitor

// Wiring: Module Pin ==> Arduino Pin
//                OUT ==> A0


void setup()
{
  Serial.begin(9600);          // setup uart baud rate
  digitalWrite(A0, LO);       // set pullup on analog pin 0 
                              // default the output to Logic Low
}

void loop()
{
  int ReedSW;
  ReedSW=analogRead(A0);      //Read hall module Vout pin value
  
  Serial.print("ReedSW value= ");        
  Serial.print(ReedSW);        //Show reed switch voltage value
  
  
  if(ReedSW>625)              //if value > 625 , short circuit
     Serial.print("  Short circuit, output = High"); 
  else                        // if< = 625 , open circuit
     Serial.print("  Open circuit, output = Low"); 
     
       
  Serial.println();
  delay(1000);
}

