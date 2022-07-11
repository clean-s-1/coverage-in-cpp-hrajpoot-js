#include "limit_breach.h"

int CollingType::fetchLowerLimit()
{
    return _lowerLimit; 
}

int CollingType::fetchUpperLimit()
{
    return _upperLimit; 
}


BreachType Breach::inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType Breach::classifyTemperatureBreach(double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;

  if(_collingType)
      return inferBreach(temperatureInC, _collingType->fetchLowerLimit(), _collingType->fetchUpperLimit());
  
  return UN_KNOWN;
}
