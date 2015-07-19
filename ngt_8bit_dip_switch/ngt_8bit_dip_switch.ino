// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: 8-bit DIP Switch
// Module Number: #ngt-di-dip8-1A
// Description: Show the status of  DIP switch in serial monitor.

// Wiring: Module Pin ==> Arduino Pin
//                 S0 ==> D2
//                 S1 ==> D3
//                 S2 ==> D4
//                 S3 ==> D5
//                 S4 ==> D6
//                 S5 ==> D7
//                 S6 ==> D8
//                 S7 ==> D9

// define pins
#define SW_S0 2
#define SW_S1 3
#define SW_S2 4
#define SW_S3 5
#define SW_S4 6
#define SW_S5 7
#define SW_S6 8
#define SW_S7 9

void setup() 
{ 
  //setup uart baud rate.
  Serial.begin(9600);  
  //initialize the digital pin as an output.
  pinMode(SW_S0, INPUT);
  pinMode(SW_S1, INPUT);
  pinMode(SW_S2, INPUT);
  pinMode(SW_S3, INPUT);
  pinMode(SW_S4, INPUT);
  pinMode(SW_S5, INPUT);
  pinMode(SW_S6, INPUT);
  pinMode(SW_S7, INPUT);
  
  Serial.println("  S7  S6  S5  S4  S3  S2  S1  S0");
  Serial.println("--------------------------------");
}

int count=1;
int table[8]={0,0,0,0,0,0,0,0};

void loop()
{
    if(digitalRead(SW_S7) == HIGH)        //DIP switch S7 in HIGH
      table[7]=1;
    else if(digitalRead(SW_S7) == LOW)    //DIP switch S7 in LOW
      table[7]=0;
      
    if(digitalRead(SW_S6) == HIGH)        //DIP switch S6 in HIGH
      table[6]=1;
    else if(digitalRead(SW_S6) == LOW)    //DIP switch S6 in LOW
      table[6]=0;
      
    if(digitalRead(SW_S5) == HIGH)        //DIP switch S5 in HIGH
      table[5]=1;
    else if(digitalRead(SW_S5) == LOW)    //DIP switch S5 in LOW
      table[5]=0;
      
    if(digitalRead(SW_S4) == HIGH)        //DIP switch S4 in HIGH
      table[4]=1;
    else if(digitalRead(SW_S4) == LOW)    //DIP switch S4 in LOW
      table[4]=0;
      
    if(digitalRead(SW_S3) == HIGH)        //DIP switch S3 in HIGH
      table[3]=1;
    else if(digitalRead(SW_S3) == LOW)    //DIP switch S3 in LOW
      table[3]=0;
      
    if(digitalRead(SW_S2) == HIGH)        //DIP switch S2 in HIGH
      table[2]=1;
    else if(digitalRead(SW_S2) == LOW)    //DIP switch S2 in LOW
      table[2]=0;
      
    if(digitalRead(SW_S1) == HIGH)        //DIP switch S1 in HIGH
      table[1]=1;
    else if(digitalRead(SW_S1) == LOW)    //DIP switch S1 in LOW
      table[1]=0;
    
    if(digitalRead(SW_S0) == HIGH)        //DIP switch S0 in HIGH
      table[0]=1;
    else if(digitalRead(SW_S0) == LOW)    //DIP switch S0 in LOW
      table[0]=0;
      
    for(int i=7;i>=0;i--)                //Show DIP switch status
    {
       Serial.print("   ");
       Serial.print(table[i]);
    }
    Serial.println();
    delay(1000);
    count++;
 
    if(count==10)
    {
       Serial.println();
       Serial.println("  S7  S6  S5  S4  S3  S2  S1  S0");
       Serial.println("--------------------------------");
       count=1;
    }
  
}






