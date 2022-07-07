#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "limit_breach.h"

TEST_CASE("case 1: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = PASSIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, 36);
  REQUIRE(breachObj.fetchBreachType() == TOO_HIGH);
}

TEST_CASE("case 2: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = PASSIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, -1);
  REQUIRE(breachObj.fetchBreachType() == TOO_LOW);
}

TEST_CASE("case 3: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = PASSIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, 25);
  REQUIRE(breachObj.fetchBreachType() == NORMAL);
}


TEST_CASE("case 4: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = HI_ACTIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, 46);
  REQUIRE(breachObj.fetchBreachType() == TOO_HIGH);
}


TEST_CASE("case 5: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = HI_ACTIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, -1);
  REQUIRE(breachObj.fetchBreachType() == TOO_LOW);
}


TEST_CASE("case 6: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = HI_ACTIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, 35);
  REQUIRE(breachObj.fetchBreachType() == NORMAL);
}


TEST_CASE("case 7: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = MED_ACTIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, 41);
  REQUIRE(breachObj.fetchBreachType() == TOO_HIGH);
}

TEST_CASE("case 8: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = MED_ACTIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, -1);
  REQUIRE(breachObj.fetchBreachType() == TOO_LOW);
}

TEST_CASE("case 9: check and alert") {
  Breach breachObj;
  BatteryCharacter batteryCharacter;
  batteryCharacter.coolingType = MED_ACTIVE_COOLING;

  checkAndAlert(TO_CONTROLLER, batteryCharacter, 39);
  REQUIRE(breachObj.fetchBreachType() == NORMAL);
}

