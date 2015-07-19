// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: Touch Button
// Module Number: #ngt-di-tchbtn-1A
// Description:Using touch button to count up and down in serial monitor.  

// Wiring: Module Pin ==> Arduino Pin
//                OUT ==> D2

// define pins
#define TuBtn 2

void setup() 
{ 
  //The setup uart baud rate.
  Serial.begin(9600);
  pinMode(TuBtn, INPUT);
  
  Serial.println("Please touch the button");
}

int TouchCount=0;

void loop()
{
  if(digitalRead(TuBtn)==HIGH)        //touch button count up
  { 
     Serial.print("Count= ");
     Serial.println(TouchCount++);
     delay(200);
  }
  else if(digitalRead(TuBtn)==LOW && TouchCount > 0)  
  {                                   //release button count down
     Serial.print("Count= ");
     Serial.println(--TouchCount);
     delay(1000);
  }  
   
  
}




