#ifndef DisplayManager_h
#define Display_Manager_h

#include <Arduino.h>
#include <TFT_eSPI.h>

class DisplayManager {

public:
    DisplayManager(TFT_eSPI& lcd, TFT_eSprite& sprite);
    void init();
    void updateDisplay(float remainingPints, float measuredBeerMass, float currentMass);

private:
    TFT_eSPI& lcd;
    TFT_eSprite& sprite;
    void drawHeader();
    void drawFooter();

};

#endif