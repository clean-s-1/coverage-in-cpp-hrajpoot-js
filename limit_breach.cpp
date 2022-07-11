#include "limit_breach.h"

int BatteryCoolingType::fetchLowerLimit()
{
    return _lowerLimit; 
}

int BatteryCoolingType::fetchUpperLimit()
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

  if(_coolingType)
      return inferBreach(temperatureInC, _coolingType->fetchLowerLimit(), _coolingType->fetchUpperLimit());
  
  return UN_KNOWN;
}
