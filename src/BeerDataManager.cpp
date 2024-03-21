#include "BeerDataManager.h"

BeerData beerData;

bool BeerDataManager::loadAndParse(const char* filename) {
    File file = SPIFFS.open(filename, "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }

    size_t size = file.size();
    std::unique_ptr<char[]> buf(new char[size]);
    file.readBytes(buf.get(), size);
    file.close();

    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, buf.get());
    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return false;
    }

    beerData.beerName = doc["beer_name"].as<String>();
    beerData.beerType = doc["beer_type"].as<String>();
    beerData.bitterness = doc["bitterness"].as<int>();
    beerData.brewDate = doc["brew_date"].as<String>();

    return true;
}

BeerData BeerDataManager::getBeerData() const {
    return beerData;
}
