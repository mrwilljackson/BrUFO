#include "BeerData.h"


bool BeerData::parseJson(String json) {
  JsonDocument doc; // Adjust size based on your JSON
  DeserializationError error = deserializeJson(doc, json);
  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return false;
  }

  beerName = doc["beer_name"].as<String>();
  beerType = doc["beer_type"].as<String>();
  bitterness = doc["bitterness"].as<int>();
  brewDate = doc["brew_date"].as<String>();

  return true;
}