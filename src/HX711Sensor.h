#ifndef HX711Sensor_h
#define HX711Sensor_h

#include "Arduino.h"
#include <HX711_ADC.h>

class HX711Sensor {
  public:
    HX711Sensor(int dout, int sck);
    void begin(float calibrationValue, unsigned long stabilizingTime = 2000, boolean tare = true);
    bool update();
    float read();
    void tare();
    
  private:
    HX711_ADC LoadCell;
    boolean newDataReady = false;
    unsigned long lastUpdateTime = 0;
    const unsigned long serialPrintInterval = 1000; // can be adjusted or set via a method
};
#endif
