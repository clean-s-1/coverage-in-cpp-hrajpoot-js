#include "typewise-alert.h"
#include "limit_breach.h"
#include <stdio.h>
#include "alerter.h"

void checkAndAlert(
    AlertTarget alertTarget, BatteryCoolingType *coolingType, double temperatureInC) {

  Breach breachObj(coolingType);
  BreachType breachType = breachObj.classifyTemperatureBreach(temperatureInC);

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
