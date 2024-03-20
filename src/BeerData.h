#ifndef BEERDATA_H
#define BEERDATA_H

#include <Arduino.h>
#include <ArduinoJson.h> // Make sure this include is correct for your setup

class BeerData {
public:
  String beerName;
  String beerType;
  int bitterness;
  String brewDate;
  
  bool parseJson(String json);
};

#endif // BEERDATA_H