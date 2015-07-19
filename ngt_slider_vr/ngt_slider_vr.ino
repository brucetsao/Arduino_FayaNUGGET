// Faya-Nugget Sample Code 
// Date: 2015/1/26
// Module Name: Slide Potentiometer
// Module Number: #ngt-ot-sldvr-1A
// Description: Detect the resistance value of slide potentiometer (0~10K) and show in series monitor.  
//              Note1: the tolerance of the resistrance is ignored.
//              Note2: the resistance is measured between GND and Ouput Terminal (terminal C)

// Wiring: Module Pin ==> Arduino Pin
//                VCC ==> A
//                  B ==> A0
//                GND ==> C



void setup()
{
  Serial.begin(9600);          //the setup uart baud rate
}

void loop()
{
  int SldVR_10K;
  
  SldVR_10K=analogRead(A0);             //Read analog pin-0 value
  
  Serial.print("Current resistance (0~10K) = ");       
  SldVR_10K=map(SldVR_10K,1023,0,10000,0);
  Serial.print(SldVR_10K);               //Show Slide VR 10K value
  Serial.println(" ohm"); 
  
  Serial.println("...........................");   
  delay(1000);
  
}
