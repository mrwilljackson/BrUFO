#ifndef BEER_DATA_PARSER_H
#define BEER_DATA_PARSER_H

#include <ArduinoJson.h>

const size_t BEER_DATA_CAPACITY = 512; // Adjust this value based on your JSON data size

struct BeerData {
  String beer_name;
  String beer_type;
  int bitterness;
  String brew_date;
};

class BeerDataParser {
public:
  BeerDataParser();
  bool parseBeerData(const char* json_data, BeerData& beer_data);

private:
  DynamicJsonDocument doc;
};

#endif