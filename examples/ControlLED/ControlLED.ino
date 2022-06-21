#include "LedRGB.h"

#define COLOR_YELLOW    0xFFE0
#define COLOR_RED       0xF800
#define COLOR_GREEN     0x07E0

LedRGB  LedRBG;

const int ledPinR = GPIO_NUM_26;
const int ledPinG = GPIO_NUM_27;
const int ledPinB = GPIO_NUM_14;

void setup() 
{
  // put your setup code here, to run once:
  LedRBG.initLedRGB(ledPinR,ledPinG,ledPinB);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  LedRBG.ledRBGWrite(COLOR_YELLOW);
  delay(1000);
  LedRBG.ledRBGWrite(COLOR_RED);
  delay(1000);
  LedRBG.ledRBGWrite(COLOR_GREEN);
  delay(1000);
}
