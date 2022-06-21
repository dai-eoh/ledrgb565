#ifndef _LedRGB_h_
#define _LedRGB_h_
#include "Arduino.h"
#include "eeprom.h"
#define ledChannelR  0
#define ledChannelG  1
#define ledChannelB  2
class LedRGB
{
    public:
    void initLedRGB(uint16_t r, uint16_t g, uint16_t b);
    uint32_t ledRBGWrite(uint16_t rgb565);
    private:
    uint32_t convert565To888(uint16_t rgb565);

    const int freq = 5000;

    const int resolution = 8;
    
    uint16_t _ledPinR;
    uint16_t _ledPinG;
    uint16_t _ledPinB;
    uint16_t _rValue;
    uint16_t _gValue;
    uint16_t _bValue;


};

#endif
