#include "LedRGB.h"

void LedRGB::initLedRGB(uint16_t r, uint16_t g, uint16_t b)
{
    _ledPinR = r;
    _ledPinG = g;
    _ledPinB = b;
    ledcSetup(ledChannelR, freq, resolution);
    ledcSetup(ledChannelG, freq, resolution);
    ledcSetup(ledChannelB, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(_ledPinR, ledChannelR);
    ledcAttachPin(_ledPinG, ledChannelG);
    ledcAttachPin(_ledPinB, ledChannelB);
}

uint32_t LedRGB::convert565To888(uint16_t rgb565)
{
//    if(rgb565 == 0x00)
//    {
//      _rValue = 256;
//      _gValue = 256;
//      _bValue = 256;
//      return 0;
//    }
    _rValue = ((rgb565 >> 11) & 0x1F);
    _gValue = ((rgb565 >> 5) & 0x3F);
    _bValue = ((rgb565) & 0x1F);
    
    _rValue = 256 - (_rValue * 255) / 31;
    _gValue = 256 - (_gValue * 255) / 63;
    _bValue = 256 - (_bValue * 255) / 31;

    uint32_t rbg32b = ((_rValue << 16) & 0xFF0000) + ((_gValue << 8 ) & 0x00FF00) + (_bValue & 0x0000FF);
    
    return rbg32b;
}


uint32_t LedRGB::ledRBGWrite(uint16_t rgb565)
{
    uint32_t rgb32b = convert565To888(rgb565);
//    Serial.println(_rValue);
//    Serial.println(_gValue);
//    Serial.println(_bValue);
    ledcWrite(ledChannelR, _rValue);
    ledcWrite(ledChannelG, _gValue);
    ledcWrite(ledChannelB, _bValue);

//    ledcWrite(ledChannelR, 0);
//    ledcWrite(ledChannelG, 255);
//    ledcWrite(ledChannelB, 0); 

    return rgb32b;
}
