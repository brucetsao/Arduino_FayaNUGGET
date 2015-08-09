#define Buz 11      //You can connect Buzzer Module(#ngt-mm-embuzr) to pin11

void setup() 
{ 
  //setup uart baud rate.
  Serial.begin(9600);
}

void loop()
{
  int vr = analogRead(A0) ;
  
  if((vr/128)== 0 )    //Diatonic scale Do
  {
    Serial.println("Do  Frequency= 262 Hz");
    tone(Buz,262);
    delay(200); 
  }
  
  if((vr/128)== 1 )    //Diatonic scale Do
  {
    Serial.println("Re  Frequency= 294 Hz");
    tone(Buz,294);
    delay(200); 
  }
  
  if((vr/128)== 2 )    //Diatonic scale Do
  {
    Serial.println("Mi  Frequency= 330 Hz");
    tone(Buz,330);
    delay(200); 
  }
  
  if((vr/128)== 3 )    //Diatonic scale Do
  {
    Serial.println("Fa  Frequency= 349 Hz");
    tone(Buz,349);
    delay(200); 
  }
  
  if((vr/128)== 4 )    //Diatonic scale Do
  {
    Serial.println("So  Frequency= 392 Hz");
    tone(Buz,392);
    delay(200); 
  }
  
  if((vr/128)== 5 )    //Diatonic scale Do
  {
    Serial.println("La  Frequency= 440 Hz");
    tone(Buz,440);
    delay(200); 
  }
  
  if((vr/128)== 6 )    //Diatonic scale Do
  {
    Serial.println("Si  Frequency= 494 Hz");
    tone(Buz,494);
    delay(200); 
  }
  
  if((vr/128)== 7 )    //Diatonic scale Do
  {
    Serial.println("Do' Frequency= 523 Hz");
    tone(Buz,523);
    delay(200); 
  }
  
  noTone(Buz);
}


