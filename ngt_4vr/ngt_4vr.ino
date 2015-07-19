// Faya-Nugget Sample Code 
// Date: 2015/1/26
// Module Name: Variable Resistor
// Module Number: #ngt-ot-vr4-1A
// Description: Detect 4 sets of resistance values from variable resistor and show in serial monitor.  
//              Note1: the tolerance of the resistrance is ignored.
//              Note2: the resistance is measured between GND and Ouput Terminal (terminal B/G/T/Y)

// Wiring: Module Pin ==> Arduino Pin
//                VCC ==> A
//                  B ==> A0  (1K range)
//                GND ==> C
//                GND ==> F
//                  G ==> A1  (10K range) 
//                VCC ==> H
//                VCC ==> S
//                  T ==> A2  (100K range)
//                GND ==> U
//                GND ==> X
//                  G ==> A3  (1M range)
//                VCC ==> Z

void setup()
{
  Serial.begin(9600);          //the setup uart baud rate
}

void loop()
{
  int value;
  int VR_1K;
  int VR_10K;
  int VR_100K;
  int VR_1M;
  
  VR_1K=analogRead(A0);       //Read analog pin-0 value
  VR_10K=analogRead(A1);      //Read analog pin-1 value
  VR_100K=analogRead(A2);     //Read analog pin-2 value
  VR_1M=analogRead(A3);       //Read analog pin-3 value
  
  Serial.print("VR_1K  = ");       //Show VR 1K value
  value=map(VR_1K,1023,0,1000,0);
  Serial.print(value);    
  Serial.println(" ohm"); 
  
  Serial.print("VR_10K = ");      //Show VR 10K value
  value=map(VR_10K,1023,0,10000,0);
  Serial.print(value); 
  Serial.println(" ohm");  
  
  Serial.print("VR_100K= ");      //Show VR 100K value
  value=map(VR_100K,1023,0,100,0);
  Serial.print(value);
  Serial.println(" K ohm");  
  
  Serial.print("VR_1M  = ");       //Show VR 1M value
  value=map(VR_1M,1023,0,1000,0);
  Serial.print(value);
  Serial.println(" K ohm");
  
  
  Serial.println("...........................");   
  delay(1000);
}
