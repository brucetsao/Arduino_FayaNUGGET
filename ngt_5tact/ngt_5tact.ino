// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: 5-bit TACT Switch
// Module Number: #ngt-di-TACT5-1A
// Description: Show the status of TACT switch in serial monitor

// Wiring: Module Pin ==> Arduino Pin
//                PB0 ==> D2
//                PB1 ==> D3
//                PB2 ==> D4
//                PB3 ==> D5
//                PB4 ==> D6

// define pins
#define SW_PB0 2
#define SW_PB1 3
#define SW_PB2 4
#define SW_PB3 5
#define SW_PB4 6

void setup() 
{ 
  //setup uart baud rate.
  Serial.begin(9600);  
  //initialize the digital pin as an output.
  pinMode(SW_PB0, INPUT);
  pinMode(SW_PB1, INPUT);
  pinMode(SW_PB2, INPUT);
  pinMode(SW_PB3, INPUT);
  pinMode(SW_PB4, INPUT);

  Serial.println("Please press a switch:");
}

void loop()
{
  if(digitalRead(SW_PB0) == HIGH)    //Press PB0 switch
    {Serial.println("PB0");
    delay(200);}
  if(digitalRead(SW_PB1) == HIGH)    //Press PB1 switch
    {Serial.println("PB1");
    delay(200);}
  if(digitalRead(SW_PB2) == HIGH)    //Press PB2 switch
   {Serial.println("PB2");
    delay(200);}
  if(digitalRead(SW_PB3) == HIGH)    //Press PB3 switch
    {Serial.println("PB3");
    delay(200);}
  if(digitalRead(SW_PB4) == HIGH)    //Press PB4 switch
    {Serial.println("PB4");
    delay(200);}


}



