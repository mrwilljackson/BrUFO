#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include "BeerDataManager.h"

class DisplayManager {

public:
    DisplayManager(TFT_eSPI& lcd, TFT_eSprite& sprite);
    void init();
    void updateDisplay(BeerData& beerData, float remainingPints, float measuredBeerMass, float currentMass);

private:
    TFT_eSPI& lcd;
    TFT_eSprite& sprite;
    void drawHeader(BeerData& beerData);
    void drawFooter(BeerData& beerData);

};

#endif