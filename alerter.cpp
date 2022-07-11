#include "alerter.h"

void Alerter::composeAnEmail(const char* recepient, const char* message)
{
    printf("To: %s\n", recepient);
    printf("Hi, the temperature is too %s\n", message);
}

void Alerter::composeControllerMsg(BreachType breachType, const unsigned short header)
{
    printf("%x : %x\n", header, breachType);
}

void Alerter::sendToController(BreachType breachType) {
  composeControllerMsg(breachType, 0xfeed);
}

void Alerter::sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  if(breachType == TOO_LOW)
  {
      composeAnEmail(recepient, "low");
  }

  if(breachType == TOO_HIGH)
  {
      composeAnEmail(recepient, "high");
  }
}

