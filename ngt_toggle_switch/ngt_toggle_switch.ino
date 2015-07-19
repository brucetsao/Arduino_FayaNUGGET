// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: Toggle Switch
// Module Number: #ngt-di-toggle3-1A
// Description: Use toggle switch to control a 24-hour timer in serial monitor.  
//              S0/S1 => switch time format (12hr / 24hr)
//              S2 => normal count speed 
//              S3 => x10 count speed
//              S4 => start / stop counting
//              S5 => reset timer to 0H : 0M: 0S

// Wiring: Module Pin ==> Arduino Pin
//                 S0 ==> D2
//                 S1 ==> D3
//                 S2 ==> D4
//                 S3 ==> D5
//                 S4 ==> D6
//                 S5 ==> D7

// define pins
#define TogS0 2
#define TogS1 3
#define TogS2 4
#define TogS3 5
#define TogS4 6
#define TogS5 7

int timer[3]={00,00,0};
int ShowMode=0;
int TimeMode=1;
int delaytime=1000;

void setup() 
{ 
  //setup uart baud rate.
  Serial.begin(9600);
  
  pinMode(TogS0, INPUT);
  pinMode(TogS1, INPUT);
  pinMode(TogS2, INPUT);
  pinMode(TogS3, INPUT);
  pinMode(TogS4, INPUT);
  pinMode(TogS5, INPUT);
  
  Serial.println("Timer :");
  
}



void loop()
{
  
  if(digitalRead(TogS0)==HIGH)                 //detect S0 state to switch timer format
    ShowMode=0;
  
  if(digitalRead(TogS1)==HIGH)
    ShowMode=1;
  
  if(digitalRead(TogS2)==HIGH && TimeMode==1)  //duration = 1 sec
    delay(delaytime);
    
  if(digitalRead(TogS3)==HIGH && TimeMode==1)  //duration 0.1 sec
    delay(delaytime/10);
    
  if(digitalRead(TogS4)==HIGH)                 //timer start
    TimeMode=1;
  else
    TimeMode=0;                                //timer  stop
  
  if(digitalRead(TogS5)==HIGH)                 //timer reset to 0H :0M :0S
    for(int i=0;i<3;i++)
      timer[i]=0;
      
  ShowTime();   
  
}


void ShowTime()           //display timer
{
  if(TimeMode==1)
  {  
      timer[2]++;
      if(timer[2]==60)
      {
        timer[2]=0;
        timer[1]++;
        if(timer[1]==60)
        {
          timer[1]=0;
          timer[0]++;
          if(timer[0]==25)
              timer[0]=0;    
        }
      }  
     
     if(ShowMode==1)
     {
       Serial.print("   ");
       Serial.print(timer[0]);
       Serial.print(" H: ");
     }
     else if(ShowMode==0)
     {
       if(timer[0]<13)
       {
         Serial.print("AM  ");
         Serial.print(timer[0]);
         Serial.print(" H: ");
       }
       else if(timer[0]>=13)
       {
         Serial.print("PM  ");
         Serial.print(timer[0]-12);
         Serial.print(" H: ");
       }
     }
      
     if(timer[1]<10)
       Serial.print(" ");
     Serial.print(timer[1]);
     Serial.print(" M: ");
      
     if(timer[2]<10)
       Serial.print(" ");
     Serial.print(timer[2]);
     Serial.println(" S ");
  }
}

