#include "typewise-alert.h"
#include <bits/stdc++.h>


class Alerter
{
    public:
    void sendToController(BreachType breachType);
    void sendToEmail(BreachType breachType);
    void composeAnEmail(const char* recepient, const char* message);
    void composeControllerMsg(BreachType breachType, const unsigned short header);
};
