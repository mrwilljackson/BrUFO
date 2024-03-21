#ifndef BEERDATAMANAGER_H
#define BEERDATAMANAGER_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FS.h>
#ifdef ESP32
#include <SPIFFS.h> // For ESP32, include SPIFFS.h
#endif

class BeerData {
public:
    String beerName;
    String beerType;
    int bitterness;
    String brewDate;

    // Constructor, Copy Constructor, and other necessary member functions
};

class BeerDataManager {
public:
    BeerDataManager() = default;
    bool loadAndParse(const char* filename);
    BeerData getBeerData() const;

private:
    BeerData beerData;
};

#endif // BEERDATAMANAGER_H
