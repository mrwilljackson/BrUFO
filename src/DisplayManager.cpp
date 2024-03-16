#include "DisplayManager.h"

DisplayManager::DisplayManager(TFT_eSPI& lcd, TFT_eSprite& sprite)
    : lcd(lcd), sprite(sprite) {}

void DisplayManager::init() {
    // Initialist the display, set up the sprite etc
}

void DisplayManager::updateDisplay(float remainingPints, float measuredBeerMass, float currentMass) {
    sprite.setTextColor(TFT_ORANGE, 0xFF58, true);
    sprite.drawString(String(remainingPints, 2), 20, 70, 4);
    sprite.setTextColor(TFT_DARKGREY, 0xFF58, true);
    sprite.drawString("pints left", 20, 90, 2);
    sprite.drawString(String(measuredBeerMass, 1), 20, 135, 2);
    sprite.drawString(String(currentMass, 1), 20, 150, 2);

    drawHeader();
    drawFooter();

    sprite.pushSprite(0, 0);
}

void DisplayManager::drawHeader() {
    sprite.setTextColor(TFT_BLACK, 0xFF58, true);
    sprite.drawString("American Pale", 220, 60, 2);
    sprite.drawString("IPA 4.5%", 220, 80, 2);
    sprite.drawString("IBU 32", 220, 100, 2);
}

void DisplayManager::drawFooter() {
    sprite.setTextColor(TFT_BLACK, 0xFF58, true);
    sprite.drawString("20 Feb 2024", 220, 150, 2);
}
