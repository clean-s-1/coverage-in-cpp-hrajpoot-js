#include "typewise-alert.h"
#include <stdio.h>
#include "alerter.h"
#include "limit_breach.h"

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  Breach breachObj;
  BreachType breachType = breachObj.classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  breachObj.set_breachType(breachType);

  Alerter alert;
  switch(alertTarget) {
    case TO_CONTROLLER:
      alert.sendToController(breachType);
      break;
    case TO_EMAIL:
      alert.sendToEmail(breachType);
      break;
  }
}
