// Faya-Nugget Sample Code 
// Date: 2015/1/28
// Module Name: 5x7 Matrix Display
// Module Number: #ngt-dp-matrix57-1A
// Description:Prtint a letter "R" on 5x7 dot matrix display.

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

//define pins
int C1=13;
int C2=12;
int C3=11;
int C4=10;
int C5=9;
int Row1=8;
int Row2=7;
int Row3=6;
int Row4=5;
int Row5=4;
int Row6=3;
int Row7=2;

// 5x7 LED Matrix
const byte COLS = 5; // 5 Columns
const byte ROWS = 7; // 7 Rows
void setup()
{
    initPins() ;
  clearLEDs();
  
}

int pictureA[7][5]={{0,0,1,0,0},    //define deiplay pattern "A"
                    {0,1,0,1,0},    
                    {1,0,0,0,1},
                    {1,0,0,0,1},
                    {1,1,1,1,1},
                    {1,0,0,0,1},
                    {1,0,0,0,1}};
                    
int pictureR[7][5]={{1,1,1,1,0},    ///define deiplay pattern "R"
                    {1,0,0,0,1},    
                    {1,0,0,0,1},
                    {1,1,1,1,0},
                    {1,0,1,0,0},
                    {1,0,0,1,0},
                    {1,0,0,0,1}};                   
                 
void loop()
{
  
  PrintPicture( pictureR );          //print R
  
}

void PrintPicture(int temp[7][5])
{    
  int oldi = 0 ;
  int 
  for(int i=0;i<5;i++)
  {
     digitalWrite(i+9,LOW); 
    for(int j=0;j<7;j++)
    {   
      if(temp[j][i]==1)
        digitalWrite(8-j,HIGH); 
      else
        digitalWrite(8-j,LOW);
    }
    delay(2);  
  }
  
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
