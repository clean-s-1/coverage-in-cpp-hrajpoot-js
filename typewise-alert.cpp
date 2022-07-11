#include "typewise-alert.h"
#include <stdio.h>
#include "alerter.h"
#include "limit_breach.h"

void checkAndAlert(
    AlertTarget alertTarget, CollingType *collingType, double temperatureInC) {

  Breach breachObj(collingType);
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
