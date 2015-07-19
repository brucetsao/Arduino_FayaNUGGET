#define MAX_NUM 12
#define ROWS 7
#define COLS 5

// Define 5x7 LED Row & Column Pin
const int row[ROWS] = {8, 7, 6, 5, 4, 3, 2};
const int col[COLS] = {9, 10, 11, 12, 13};

// Matrix LED
//  C4 C3 C2 C1 C0
//  O  O  O  O  O  R6
//  O  O  O  O  O  R5
//  O  O  O  O  O  R4
//  O  O  O  O  O  R3
//  O  O  O  O  O  R2
//  O  O  O  O  O  R1
//  O  O  O  O  O  R0
const char matrix[MAX_NUM][ROWS] = {
  {0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F}, // Number: 0
  {0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}, // Number: 1
  {0x1F, 0x01, 0x01, 0x1F, 0x10, 0x10, 0x1F}, // Number: 2
  {0x1F, 0x01, 0x01, 0x1F, 0x01, 0x01, 0x1F}, // Number: 3
  {0x11, 0x11, 0x11, 0x1F, 0x01, 0x01, 0x01}, // Number: 4
  {0x1F, 0x10, 0x10, 0x1F, 0x01, 0x01, 0x1F}, // Number: 5
  {0x1F, 0x10, 0x10, 0x1F, 0x11, 0x11, 0x1F}, // Number: 6
  {0x1F, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01}, // Number: 7
  {0x1F, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x1F}, // Number: 8
  {0x1F, 0x11, 0x11, 0x1F, 0x01, 0x01, 0x1F}, // Number: 9
  {0x00, 0x15, 0x0A, 0x1F, 0x0E, 0x15, 0x00}, // Number: *
  {0x00, 0x0A, 0x1F, 0x0A, 0x1F, 0x0A, 0x00}, // Number: #
};

int gNum;

void clearLEDs(void) {
  for (int r = 0; r < ROWS; r++) {
    digitalWrite(row[r], LOW);
  }
  
  for (int c = 0; c < COLS; c++) {
    digitalWrite(col[c], HIGH);
  }
}

void writeNum(int num) {
    gNum = num;
}

void refreshMatrix(void) {
  int r, c, onOff;
  char mask;

  for (r = 0; r < ROWS; r++) {
    digitalWrite(row[r], HIGH);
 mask = 0x10;

    for (c = 0; c < COLS; c++, mask >>= 1) {
      onOff = matrix[gNum][r] & mask;
      if (onOff)
        digitalWrite(col[c], LOW);
      
      delayMicroseconds(50);
      digitalWrite(col[c], HIGH);
    }

    digitalWrite(row[r], LOW);
  }
}

void setup() {
  for (int r = 0; r < ROWS; r++) {
    pinMode(row[r], OUTPUT);
  }
  
  for (int c = 0; c < COLS; c++) {
    pinMode(col[c], OUTPUT);
  }
  
  clearLEDs();
  writeNum(0);
}

void loop() {
  // Refresh 5x7 Matrix LEDs
  for (int i = 0; i < 1000; i++)
    refreshMatrix();
  
  // Display next number
  if (++gNum >= MAX_NUM) {
    gNum = 0;
  }
}
