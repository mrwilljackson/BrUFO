#include "BeerDataParser.h"

// BeerDataParser::BeerDataParser()
//   : doc(BEER_DATA_CAPACITY) {}

// bool BeerDataParser::parseBeerData(const char* json_data, BeerData& beer_data) {
//   DeserializationError error = deserializeJson(doc, json_data);

//   if (error) {
//     Serial.print(F("deserializeJson() failed: "));
//     Serial.println(error.f_str());
//     return false;
//   }

//   beer_data.beer_name = doc["beer_name"].as<String>();
//   beer_data.beer_type = doc["beer_type"].as<String>();
//   beer_data.bitterness = doc["bitterness"].as<int>();
//   beer_data.brew_date = doc["brew_date"].as<String>();

//   doc.garbageCollect();
//   return true;
// }