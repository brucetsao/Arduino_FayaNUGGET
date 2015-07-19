/* Pin Mapping for Kingbright Common Cathode 5x7 LED Matrix 
// Wiring: Module Pin ==> Arduino Pin
//                 C1 ==> D13
//                 C2 ==> D12
//                 C3 ==> D11
//                 C4 ==> D10
//                 C5 ==> D9
//               Row1 ==> D8
//               Row2 ==> D7
//               Row3 ==> D6
//               Row4 ==> D5
//               Row5 ==> D4
//               Row6 ==> D3
//               Row7 ==> D2
     
    Arduino pin2~pin8 = row0~row6, so rowX +2 = pin number
    Arduino pin13~pin9 = column0~column4, 13 - columnY = pin number    
*/

// 5x7 LED Matrix
const byte COLS = 5; // 5 Columns
const byte ROWS = 7; // 7 Rows



void setup() {
  
    initPins() ;
 
}

void loop() {
  clearLEDs();
  
  // 往下而下，一排一排(Row)打開
  for (int r = 0; r < ROWS; r++) {
    digitalWrite( r + 2, HIGH);
    delay(300);
  }
  
  // 往左而右，一行一行(Column)關掉
  for (int c = 0; c < COLS; c++) {
    digitalWrite(13 - c, HIGH);
    delay(300);
  }  

  // 暫停 1 秒鐘
  delay(1000);
}


void initPins()
{
  //                 C1 ==> D13
//                 C2 ==> D12
//                 C3 ==> D11
//                 C4 ==> D10
//                 C5 ==> D9
//               Row1 ==> D8
//               Row2 ==> D7
//               Row3 ==> D6
//               Row4 ==> D5
//               Row5 ==> D4
//               Row6 ==> D3
//               Row7 ==> D2
  // 5x7 LED Matrix 接在 pin 2 ~ pin 13
  // 把腳位設置為 output pin
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
  
}
void clearLEDs() {
  for (int r = 0; r < ROWS; r++) {
    digitalWrite( r + 2, LOW);
  }   
  
  for (int c = 0; c < COLS; c++) {
      digitalWrite( 13 - c, LOW);  // 共陰極，每一行預設均為接地(Low = 接地，High = 關燈)
  }
}  


