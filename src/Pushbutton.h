#ifndef Pushbutton_h
#define Pushbutton_h

#include <Arduino.h>

class Pushbutton {
  public:
    Pushbutton(byte pin);
    void init();
    void update();
    bool wasPressed();

  private:
    byte pin;
    byte state;
    byte lastState;
    byte lastReading;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;
    bool buttonPressed;
};

#endif
