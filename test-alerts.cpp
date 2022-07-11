#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "limit_breach.h"

TEST_CASE("Case 1: infers the breach according to limits") {
  Breach breachObj;
  REQUIRE(breachObj.inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("Case 2: infers the breach according to limits") {
  Breach breachObj;
  REQUIRE(breachObj.inferBreach(31, 20, 30) == TOO_HIGH);
}
TEST_CASE("Case 3: infers the breach according to limits") {
  Breach breachObj;
  REQUIRE(breachObj.inferBreach(25, 20, 30) == NORMAL);
}

TEST_CASE("Classify the temperature breach for passive Cooling") {
  Breach breachObj(new PassiveCooling());
  REQUIRE(breachObj.classifyTemperatureBreach(12) == NORMAL);
  REQUIRE(breachObj.classifyTemperatureBreach(-1) == TOO_LOW);
  REQUIRE(breachObj.classifyTemperatureBreach(36) == TOO_HIGH);

  //limit check
  REQUIRE(breachObj._coolingType->fetchLowerLimit() == 0);
  REQUIRE(breachObj._coolingType->fetchUpperLimit() == 35);
}

TEST_CASE("Classify the temperature breach for hi active Cooling") {
  Breach breachObj(new HiActiveCooling());
  REQUIRE(breachObj.classifyTemperatureBreach(25) == NORMAL);
  REQUIRE(breachObj.classifyTemperatureBreach(-1) == TOO_LOW);
  REQUIRE(breachObj.classifyTemperatureBreach(46) == TOO_HIGH);

  //limit check
  REQUIRE(breachObj._coolingType->fetchLowerLimit() == 0);
  REQUIRE(breachObj._coolingType->fetchUpperLimit() == 45);
}

TEST_CASE("Classify the temperature breach for med active Cooling") {
  Breach breachObj(new MedActiveCooling());
  REQUIRE(breachObj.classifyTemperatureBreach(35) == NORMAL);
  REQUIRE(breachObj.classifyTemperatureBreach(-1) == TOO_LOW);
  REQUIRE(breachObj.classifyTemperatureBreach(41) == TOO_HIGH);

  //limit check
  REQUIRE(breachObj._coolingType->fetchLowerLimit() == 0);
  REQUIRE(breachObj._coolingType->fetchUpperLimit() == 40);
}

