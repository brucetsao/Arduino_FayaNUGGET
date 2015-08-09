// Faya-Nugget Sample Code 
// Date: 2015/1/28
// Module Name: 3V DC Motor
// Module Number: #ngt-mt-dc3v-1A
// Description: Using Arduino code to control DC motor.

// Wiring: Module Pin ==> Arduino Pin
//                SIG ==> D9
//                DIR ==> D8

// Wiring: Module Pin ==> Arduino Pin
//                VRX ==> A0
//                VRY ==> A1
//                 SW ==> A2

//define pins
int SIG = 9;
int DIR = 8;
int flag = 1 ;

void setup() 
{
  // initialize the digital pin as an output.
  pinMode(SIG,OUTPUT);
  pinMode(DIR,OUTPUT);

  //reset pin function.
  PinRester();
}

void loop()
{

   int VR_X;
  int VR_Y;
  int SW;
  VR_X=analogRead(A0);      //Read analog pin-0 value
  VR_Y=analogRead(A1);      //Read analog pin-1 value
  SW=analogRead(A2);        //Read analog pin-2 value
  
    if(SW>625)   
    {
        flag = flag *(-1) ;
    }
      
  
            if(VR_X>600) 
            {
                       analogWrite(SIG,map(VR_X,600,1023,50,255)); 
            }
                  
            if(VR_X<400) 
            {
                       analogWrite(SIG,map(VR_X,400,0,50,255)); 
            }
        
           if((VR_X>=400) && (VR_X<=600) )
                     analogWrite(SIG,0) ;

               if (flag == 1)
                  digitalWrite(DIR,LOW);   //LOW = Clockwise, HIGH = CounterClockwise
                  else
                  digitalWrite(DIR,HIGH);   //LOW = Clockwise, HIGH = CounterClockwise
} 

void PinRester()
{
  digitalWrite(SIG,LOW);
  digitalWrite(DIR,LOW);

}
