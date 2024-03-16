#include "Keg.h"

// evrerything is in grams

Keg::Keg(int id, float emptyMass, float fullMass) 
{
  this->id = id;
  this->emptyMass = emptyMass;
  this->fullMass = fullMass;
  this->currentMass = 0;
  convertGramstoPintsFactor = 0.001759754;
}

void Keg::init() 
{
  currentMass = fullMass - emptyMass;
}

void Keg::dispenseBeer(float servingMass) 
{
  currentMass += servingMass;
}

float Keg::getCurrentMass()
{
  return currentMass;
}

float Keg::getPintsRemaining()
{
  return currentMass * convertGramstoPintsFactor;
}