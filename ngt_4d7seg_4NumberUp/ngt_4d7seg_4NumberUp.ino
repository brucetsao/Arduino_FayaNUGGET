// 七段顯示器製作倒數功能 (vturnon)
#define S2 10
#define S1 11
#define EN 12
//  light up first digit set S1=0, S2=0, EN=0
//  light up 2nd digit set S1=0, S2=1, EN=0
//  light up 3rd digit set S1=1, S2=0, EN=0
//  light up 4th digit et S1=1, S2=1, EN=0

#define aPin 2
#define bPin 3
#define cPin 4
#define dPin 5
#define ePin 6
#define fPin 7
#define gPin 8
#define dotPin 9
#define turnon HIGH
#define turnoff LOW
#define digitalon HIGH
#define digitaloff LOW
int number = 0;

unsigned long time_previous;
void setup() {               
  pinMode(EN, OUTPUT);  
  pinMode(S1, OUTPUT);  
  pinMode(S2, OUTPUT);  
  pinMode(aPin, OUTPUT);  
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dotPin, OUTPUT);
  digitalWrite(dotPin, turnoff);  // 關閉小數點
   Serial.begin(9600);
  
}

void loop() {
     int i ;
  // 經過一秒後就讓number加1 
  unsigned long time_now = millis();
  if(time_now - time_previous > 1000){
    number++;
    time_previous += 1000;
 //   Serial.println("number=%d\n", number);
  }

  // 不斷地寫入數字
  showNumber(number);
}
 
 void showNumber(int no)
 {
   if (no == -1)
   {
       ShowSegment(1, -1) ;
   }
   else
   {
      ShowSegment(1, (no/1000)) ;
      delay(5) ;
      ShowSegment(2, (no/100)) ;
      delay(5) ;
      ShowSegment(3, (no/10)) ;
     delay(5) ;
      ShowSegment(4, (no%10)) ;
     delay(5) ;
   }
 }
 void ShowSegment(int digital, int number)
 {
     switch (digital)
         {
             case 4:
            digitalWrite(S1, digitaloff);
            digitalWrite(S2, digitaloff);
            digitalWrite(EN, digitaloff);

             break ;
             
             case 3:
            digitalWrite(S1, digitaloff);
            digitalWrite(S2, digitalon);
            digitalWrite(EN, digitaloff);
             break ;
             
             case 2:
            digitalWrite(S1, digitalon);
            digitalWrite(S2, digitaloff);
            digitalWrite(EN, digitaloff);
             break ;
             
             case 1:
            digitalWrite(S1, digitalon);
            digitalWrite(S2, digitalon);
            digitalWrite(EN, digitaloff);
             break ;
         }
            
    switch (number)
      {
        case 9:
                 // 顯示數字 '9'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnoff);
          digitalWrite(ePin, turnoff);
          digitalWrite(fPin, turnon);
          digitalWrite(gPin, turnon);
           break ;
           
           case 8:
          // 顯示數字 '8'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnon);
          digitalWrite(ePin, turnon);
          digitalWrite(fPin, turnon);
          digitalWrite(gPin, turnon);
          break ;
          
          case 7:
          // 顯示數字 '7'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnoff);
          digitalWrite(ePin, turnoff);
          digitalWrite(fPin, turnoff);
          digitalWrite(gPin, turnoff);
          break ;
          
          case 6:
          // 顯示數字 '6'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnoff);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnon);
          digitalWrite(ePin, turnon);
          digitalWrite(fPin, turnon);
          digitalWrite(gPin, turnon);
          break ;
          
          case 5:
          // 顯示數字 '5'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnoff);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnon);
          digitalWrite(ePin, turnoff);
          digitalWrite(fPin, turnon);
          digitalWrite(gPin, turnon);
          break ;
          
          case 4:
          // 顯示數字 '4'
          digitalWrite(aPin, turnoff);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnoff);
          digitalWrite(ePin, turnoff);
          digitalWrite(fPin, turnon);
          digitalWrite(gPin, turnon);
          break ;
          
          case 3:
          // 顯示數字 '3'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnon);
          digitalWrite(ePin, turnoff);
          digitalWrite(fPin, turnoff);
          digitalWrite(gPin, turnon);
          break ;
         
           case 2: 
          // 顯示數字 '2'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnoff);
          digitalWrite(dPin, turnon);
          digitalWrite(ePin, turnon);
          digitalWrite(fPin, turnoff);
          digitalWrite(gPin, turnon);
          break ;
          
          case 1:
          // 顯示數字 '1'
          digitalWrite(aPin, turnoff);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnoff);
          digitalWrite(ePin, turnoff);
          digitalWrite(fPin, turnoff);
          digitalWrite(gPin, turnoff);
          break ;
          
          case 0:
          // 顯示數字 '0'
          digitalWrite(aPin, turnon);
          digitalWrite(bPin, turnon);
          digitalWrite(cPin, turnon);
          digitalWrite(dPin, turnon);
          digitalWrite(ePin, turnon);
          digitalWrite(fPin, turnon);
          digitalWrite(gPin, turnoff);  
           break ;

          case -1:
          // all Off
          digitalWrite(aPin, turnoff);
          digitalWrite(bPin, turnoff);
          digitalWrite(cPin, turnoff);
          digitalWrite(dPin, turnoff);
          digitalWrite(ePin, turnoff);
          digitalWrite(fPin, turnoff);
          digitalWrite(gPin, turnoff);  
           break ;

      } 
 }

