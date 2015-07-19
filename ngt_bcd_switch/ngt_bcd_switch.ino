// Faya-Nugget Sample Code 
// Date: 2015/1/26
// Module Name: BCD Switch
// Module Number: #ngt-di-bcd-1A
// Description: She the status of BCD switch in serial monitor

// Wiring: Module Pin ==> Arduino Pin
//                  1 ==> D2
//                  2 ==> D3
//                  4 ==> D4
//                  8 ==> D5

// define pins
#define BCD_Pin1 2
#define BCD_Pin2 3
#define BCD_Pin4 4
#define BCD_Pin8 5

void setup() 
{ 
  Serial.begin(9600);          //setup uart baud rate
  // initialize the digital pin as an input.
  pinMode(BCD_Pin1, INPUT);
  pinMode(BCD_Pin2, INPUT);
  pinMode(BCD_Pin4, INPUT);
  pinMode(BCD_Pin8, INPUT);
  
  Serial.println("  P8  P4  P2  P1");
  Serial.println("------------------------");
}

int count=1;
int number=0;

void loop()
{
  int BDC_value;
  
  if(digitalRead(BCD_Pin8)==HIGH)  //BCD== 8 ,9
    {Serial.print("  1");
    number = number + 8;}
  else
    Serial.print("  0"); 
  
  if(digitalRead(BCD_Pin4)==HIGH)  //BCD== 4, 5, 6 ,7
    {Serial.print("   1");
     number = number + 4;}
  else
    Serial.print("   0"); 
  
  if(digitalRead(BCD_Pin2)==HIGH)  //BCD== 2, 3, 6 ,7
    {Serial.print("   1");
    number = number + 2;}
  else
    Serial.print("   0"); 

  if(digitalRead(BCD_Pin1)==HIGH)  //BCD== 1, 3, 5 ,7 ,9
    {Serial.print("   1");
    number = number + 1;}  
  else
    Serial.print("   0"); 
    
   Serial.print("  ==> ");
   Serial.print(number);  
   number = 0; 
 
 Serial.println();   
 delay(1000);
 count++;
 
 if(count==10)
 {
   Serial.println();
   Serial.println("  P8  P4  P2  P1");
   Serial.println("----------------------");
   count=1;
 }
   
}


