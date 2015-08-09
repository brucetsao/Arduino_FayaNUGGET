#include <FrequencyTimer2.h>
#define turnon HIGH
#define turnoff LOW


#define SPACE { \
    { 0, 0, 0, 0, 0}, \
    { 0, 0, 0, 0, 0}, \
    { 0, 0, 0, 0, 0}, \
    { 0, 0, 0, 0, 0}, \
    { 0, 0, 0, 0, 0}, \
    { 0, 0, 0, 0, 0}, \
    { 0, 0, 0, 0, 0} \
}

#define H { \
    { 1, 0,  0, 0, 1}, \
    { 1, 0,  0, 0, 1}, \
    { 1, 0,  0, 0, 1}, \
    { 1, 1,  1, 1, 1}, \
    { 1, 0,  0, 0, 1}, \
    { 1, 0,  0, 0, 1}, \
    { 1, 0,  0, 0, 1}  \
}

#define E  { \
    { 1, 1, 1, 1, 10}, \
    { 1, 0, 0, 0, 0}, \
    { 1, 0, 0, 0, 0}, \
    { 1, 1, 1, 1, 1}, \
    { 1, 0, 0, 0, 0}, \
    { 1, 0, 0, 0, 0}, \
    { 1, 1, 1, 1, 1}  \
}

#define L { \
    {1, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0}, \
    {1, 0, 0, 0, 0}, \
    {1, 1, 1, 1, 1}  \
}

#define O { \
    {0, 0, 1, 0, 0}, \
    {0, 1, 0, 1, 0}, \
    {1, 0, 0, 0, 1}, \
    {1, 0, 0, 0, 1}, \
    {1, 0, 0, 0, 1}, \
    {0, 1, 0, 1, 0}, \
    {0, 0, 1, 0, 0}  \
}

byte col = 0;
byte leds[7][5];

// Pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
int Pins[13]= {-1,2,3, 4, 5, 6, 7,8,9,10,11,12,13}; 

// col[xx] of leds = Pin yy on led matrix
int cols[5] = {Pins[8], Pins[9], Pins[10], Pins[11], Pins[12]};

// row[xx] of leds = Pin yy on led matrix
int rows[7] = {Pins[7], Pins[6], Pins[5], Pins[4], Pins[3], Pins[2], Pins[1]};

const int numPatterns = 6;
byte patterns[numPatterns][7][5] = {
  H,E,L,L,O,SPACE
};

int pattern = 0;

void setup() {
  // sets the Pins as output
  for (int i = 1; i <= 16; i++) {
    pinMode(Pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 1; i <= 5; i++) {
    digitalWrite(cols[i - 1], turnoff);
  }

  for (int i = 1; i <= 7; i++) {
    digitalWrite(rows[i - 1], turnoff);
  }

  clearLeds();

  // Turn off toggling of Pin 11
  FrequencyTimer2::disable();
  // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setPeriod(2000);
  // Set interrupt routine to be called
  FrequencyTimer2::setOnOverflow(display);

  setPattern(pattern);
}

void loop() {
 

    pattern = ++pattern % numPatterns;
    slidePattern(pattern, 200);

    
}

void clearLeds() {
  // Clear display array
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 5; j++) {
      leds[i][j] = 0;
    }
  }
}

void setPattern(int pattern) {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 5; j++) {
      leds[i][j] = patterns[pattern][i][j];
    }
  }
}

void slidePattern(int pattern, int del) {
  for (int l = 0; l < 6; l++)
  {
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 7; j++) 
          {
            leds[j][i] = leds[j][i+1];
          }
    }
    for (int j = 0; j < 7; j++) 
    {
      leds[j][4] = patterns[pattern][j][0 + l];
    }
    delay(del);
  }
}

// Interrupt routine
void display() {
  digitalWrite(cols[col], HIGH);  // Turn whole previous column off
  col++;
  if (col == 5) {
    col = 0;
  }
  for (int row = 0; row < 7; row++) {
    if (leds[row][col] == 1) {
      digitalWrite(rows[row], turnon);  // Turn on this led
    }
    else {
      digitalWrite(rows[row], turnoff); // Turn off this led
    }
  }
  digitalWrite(cols[col], turnoff); // Turn whole column on at once (for equal lighting times)
}

