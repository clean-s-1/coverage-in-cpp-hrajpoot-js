#include <bits/stdc++.h>
#include "typewise-alert.h"


class Breach
{
    private:
        static BreachType _breachType;
    public:
        BreachType inferBreach(double value, double lowerLimit, double upperLimit);
        BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

        void set_breachType(BreachType breachType);
        BreachType fetchBreachType();
};

