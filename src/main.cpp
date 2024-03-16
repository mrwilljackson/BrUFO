#include "Arduino.h"
#include "TFT_eSPI.h" /* Please use the TFT library provided in the library. */
#include "pin_config.h"
#include "Pushbutton.h"
#include "HX711Sensor.h"
#include "Keg.h"
#include "background.h"
#include "DisplayManager.h"


TFT_eSPI lcd = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&lcd);

DisplayManager displayManager(lcd, sprite);

#define blue 0x0967
#define black 0x0000

Pushbutton button1(PIN_BUTTON_1);
Pushbutton button2(PIN_BUTTON_2);

//HX711 pins:
const int HX711_dout = 16; //mcu > HX711 dout pin
const int HX711_sck = 21; //mcu > HX711 sck pin

//HX711 constructor of LoadCell object with pins
HX711Sensor LoadCell(HX711_dout, HX711_sck);

float measuredBeerMass; // beer mass reading

Keg myKeg(1, 0, 19000);

void setup() {
  Serial.begin(57600); 
  delay(10);

  // put your setup code here, to run once:
  button1.init();
  button2.init();

  displayManager.init();

  // lcd.init();
  // lcd.fillScreen(TFT_WHITE);
  // lcd.setRotation(3);
  // lcd.setSwapBytes(true);
  // lcd.fillScreen(TFT_GREEN);

  // sprite.createSprite(320, 170);
  // sprite.setSwapBytes(true);
  // sprite.pushImage(0,0,320,170, backgroundGraphic);
    
  // sprite.setTextDatum(3);
  // sprite.pushSprite(0,0);

  LoadCell.begin(22.08); // Pass the calibration value here
  
  myKeg.init(); // initialise a keg object

}

void loop() {
//   // put your main code here, to run repeatedly:
  Serial.println("loop");

  if (LoadCell.update()) { // if there is new data update the beerMass value
    measuredBeerMass = LoadCell.read();
  }

  button1.update();
  button2.update();

  if(button1.wasPressed()) {
    // sprite.fillRoundRect(6,10,170,50,4,TFT_GREEN);
    // sprite.drawString("<- Dispense",20,35,4);
    myKeg.dispenseBeer(measuredBeerMass);
  } else {
    // sprite.fillRoundRect(6,10,170,50,4,blue);
    // sprite.drawString("<- Dispense",20,35,4);
    // dispense the measuredBeerMass from the myKeg
  }

  if(button2.wasPressed()) {
    // sprite.fillRoundRect(6,110,170,50,4,TFT_GREEN);
    // sprite.drawString("<- Tare",20,135,4);
    LoadCell.tare();
  } else {
    // sprite.fillRoundRect(6,110,170,50,4,blue);
    // sprite.drawString("<- Tare",20,135,4);

  }

  // if (! button1.readState())
  // {
  //   myKeg.dispenseBeer(beerMass);
  // }

  displayManager.updateDisplay(myKeg.getPintsRemaining(), measuredBeerMass, myKeg.getCurrentMass());
 
  // if (button1.wasPressed() && button2.wasPressed())
  // {
  //   sprite.setTextColor(TFT_BLACK, 0xFFFF);
  //   sprite.fillSprite(TFT_GREEN);
  //   sprite.drawString("tare",10,85,4);
  //   LoadCell.tare();
  // }

//  if (!button1.readState()) {
//    sprite.fillSprite(TFT_RED);
//  }
  
  sprite.pushSprite(0,0);
  delay(50);
}