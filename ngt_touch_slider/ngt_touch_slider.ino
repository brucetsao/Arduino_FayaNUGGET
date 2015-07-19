// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: Touch Slider
// Module Number: #ngt-di-tchsdr8-1A
// Description: Detect the touch button and show its corresponging diatonic scale is serial monitor
//              When P7 ==> Diatonic scale Do 
//              When P6 ==> Diatonic scale Re
//              When P5 ==> Diatonic scale Mi 
//              When P4 ==> Diatonic scale Fa 
//              When P3 ==> Diatonic scale So 
//              When P2 ==> Diatonic scale La 
//              When P1 ==> Diatonic scale Si 
//              When P0 ==> Diatonic scale DO'

// Wiring: Module Pin ==> Arduino Pin
//                 P0 ==> D2
//                 P1 ==> D3
//                 P2 ==> D4
//                 P3 ==> D5
//                 P4 ==> D6
//                 P5 ==> D7
//                 P6 ==> D8
//                 P7 ==> D9

// define pins
#define TuSld_P0 2
#define TuSld_P1 3
#define TuSld_P2 4
#define TuSld_P3 5
#define TuSld_P4 6
#define TuSld_P5 7
#define TuSld_P6 8
#define TuSld_P7 9
#define TuSld_P7 9
#define Buz 11      //You can connect Buzzer Module(#ngt-mm-embuzr) to pin11

void setup() 
{ 
  //setup uart baud rate.
  Serial.begin(9600);
  
  pinMode(TuSld_P0, INPUT);
  pinMode(TuSld_P1, INPUT);
  pinMode(TuSld_P2, INPUT);
  pinMode(TuSld_P3, INPUT);
  pinMode(TuSld_P4, INPUT);
  pinMode(TuSld_P5, INPUT);
  pinMode(TuSld_P6, INPUT);
  pinMode(TuSld_P7, INPUT);
  
  Serial.println("Please touch the slider");
}

void loop()
{
  if(digitalRead(TuSld_P7)==HIGH)    //Diatonic scale Do
  {
    Serial.println("Do  Frequency= 262 Hz");
    tone(Buz,262);
    delay(200); 
  }
  
  if(digitalRead(TuSld_P6)==HIGH)    //Diatonic scale Re
  {
    Serial.println("Re  Frequency= 294 Hz");
    tone(Buz,294);
    delay(200); 
  }
  
  if(digitalRead(TuSld_P5)==HIGH)   //Diatonic scale Mi
  {
    Serial.println("Mi  Frequency= 330 Hz");
    tone(Buz,330);
    delay(200); 
  }
  
  if(digitalRead(TuSld_P4)==HIGH)   //Diatonic scale Fa 
  {
    Serial.println("Fa  Frequency= 349 Hz");
    tone(Buz,349);
    delay(200); 
  }
  
  if(digitalRead(TuSld_P3)==HIGH)   //Diatonic scale So
  {
    Serial.println("So  Frequency= 392 Hz");
    tone(Buz,392);
    delay(200); 
  }
  
  if(digitalRead(TuSld_P2)==HIGH)   //Diatonic scale La
  {
    Serial.println("La  Frequency= 440 Hz");
    tone(Buz,440);
    delay(200); 
  }
  
  if(digitalRead(TuSld_P1)==HIGH)   //Diatonic scale Si
  {
    Serial.println("Si  Frequency= 494 Hz");
    tone(Buz,494);
    delay(200); 
  }
  
  if(digitalRead(TuSld_P0)==HIGH)   //Diatonic scale Do'
  {
    Serial.println("Do' Frequency= 523 Hz");
    tone(Buz,523);
    delay(200); 
  }
  
  noTone(Buz);
}


