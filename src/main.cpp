#include "Arduino.h"
#include "TFT_eSPI.h" /* Please use the TFT library provided in the library. */
#include "pin_config.h"
#include "Pushbutton.h"
#include "HX711Sensor.h"
#include "Keg.h"
#include "background.h"
#include <SPIFFSutils.h>

TFT_eSPI lcd = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&lcd);

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

  lcd.init();
  lcd.fillScreen(TFT_WHITE);
  lcd.setRotation(3);
  lcd.setSwapBytes(true);
  lcd.fillScreen(TFT_GREEN);

  sprite.createSprite(320, 170);
  sprite.setSwapBytes(true);
  sprite.pushImage(0,0,320,170, backgroundGraphic);
    
  sprite.setTextDatum(3);
  sprite.pushSprite(0,0);

  LoadCell.begin(22.08); // Pass the calibration value here
  
  myKeg.init(); // initialise a keg object
  

  // if(!SPIFFS.begin(true)){
  //   Serial.println("An Error has occurred while mounting SPIFFS");
  //   return;
  // }
  
  // File file = SPIFFS.open("/text.txt", "r");

  // if(!file){
  //   Serial.println("Failed to open file for reading");
  //   return;
  // }
  
  // Serial.println("File Content:");
  // while(file.available()){
  //   Serial.write(file.read());
  // }
  // file.close();

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

  sprite.setTextColor(TFT_ORANGE, 0xFF58, true);
  sprite.drawString(String(myKeg.getPintsRemaining(), 2),20,70,4);
  sprite.setTextColor(TFT_DARKGREY, 0xFF58, true);
  sprite.drawString("pints left",20,90,2);

  sprite.setTextColor(TFT_DARKGREY, 0xFF58, true);
  sprite.drawString(String(measuredBeerMass,1),20,135,2);
  sprite.drawString(String(myKeg.getCurrentMass(),1),20,150,2);


  sprite.setTextColor(TFT_BLACK, 0xFF58, true);
  sprite.drawString("American Pale", 220, 60, 2);
  sprite.drawString("IPA 4.5%", 220, 80, 2);
  sprite.drawString("IBU 32", 220, 100, 2);
  sprite.drawString("20 Feb 2024", 220, 150, 2);
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