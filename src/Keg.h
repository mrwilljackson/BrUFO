#ifndef Keg_h
#define Keg_h

#include "Arduino.h"

class Keg {
  public:
    Keg(int id, float emptyMass, float fullMass);
    void init();
    void dispenseBeer(float servingMass);
    float getCurrentMass();
    float getPintsRemaining();
    // int calculateServings(float servingSize);
    // float getRemainingBeerMass();

  private:
    int id;
    float emptyMass;
    float fullMass;
    float currentMass;  
    float convertGramstoPintsFactor;
};

#endif
