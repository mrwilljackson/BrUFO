#include "HX711Sensor.h"
#include <Arduino.h>

HX711Sensor::HX711Sensor(int dout, int sck) : LoadCell(dout, sck) {}

void HX711Sensor::begin(float calibrationValue, unsigned long stabilizingTime, boolean tare) 
{
  LoadCell.begin();
  LoadCell.start(stabilizingTime, tare);
  if (!LoadCell.getTareTimeoutFlag()) {
    LoadCell.setCalFactor(calibrationValue);
    } else {
    Serial.println("HX711 initialization failed");
  }
}

boolean HX711Sensor::update() 
{
//  return LoadCell.update();
  if (LoadCell.update()) {
    newDataReady = true;
  }
  if (newDataReady && millis() - lastUpdateTime >= serialPrintInterval) {
    lastUpdateTime = millis();
    newDataReady = false;
    return true; // indicates new data is ready
  }
  return false; // indicates no new data is ready
}

float HX711Sensor::read() 
{
  return LoadCell.getData();
}

void HX711Sensor::tare() 
{
  LoadCell.tareNoDelay();
}
