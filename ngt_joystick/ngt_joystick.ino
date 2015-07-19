// Faya-Nugget Sample Code 
// Date: 2015/1/26
// Module Name: JoyStick Switch
// Module Number: #ngt-ai-jystksw-1A
// Description: Detect the motrion of the joystick and show the results in serial monitor.

// Wiring: Module Pin ==> Arduino Pin
//                VRX ==> A0
//                VRY ==> A1
//                 SW ==> A2


void setup()
{
  Serial.begin(9600);          // setup uart baud rate
}


void loop()
{
  int VR_X;
  int VR_Y;
  int SW;
  
  VR_X=analogRead(A0);      //Read analog pin-0 value
  VR_Y=analogRead(A1);      //Read analog pin-1 value
  SW=analogRead(A2);        //Read analog pin-2 value
  
  Serial.print("VR_X = ");       //Show VR X value
  Serial.println(VR_X);    
   
  Serial.print("VR_Y = ");       //Show VR Y value
  Serial.println(VR_Y);    
 
  Serial.print("SW = ");         //Show SW value
  Serial.println(SW);
  
  Serial.print("Status: ");
  if(VR_Y>600)                  //VR Y analog value > 600 is up
     Serial.print(" up ");
  if(VR_Y<500)                  //VR Y analog value < 500 is down
     Serial.print(" down ");
  if(VR_X>600)                  //VR X analog value > 600 is right
     Serial.print(" right ");
  if(VR_X<500)                  //VR X analog value < 500 is lift
     Serial.print(" left ");
  if(VR_Y<600 && VR_Y>500 && VR_X<600 && VR_X>500)
     Serial.print(" mid ");
     
  if(SW>625)                    //touch switch
     Serial.print(" SW = on ");
  else
     Serial.print(" SW = off ");
  
  Serial.println("");   
  Serial.println("...........................");   
  delay(1000);
}
