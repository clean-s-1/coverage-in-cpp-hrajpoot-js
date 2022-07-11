#include <bits/stdc++.h>
#include "typewise-alert.h"

class BatteryCoolingType
{
    private:
        int _lowerLimit;
        int _upperLimit;
    public:
        BatteryCoolingType(int lowerLimit, int upperLimit) : _lowerLimit(lowerLimit), _upperLimit(upperLimit) {}

        int fetchLowerLimit();
        int fetchUpperLimit();
};

class PassiveCooling : public BatteryCoolingType
{
    public:
       PassiveCooling() : BatteryCoolingType(0, 35) {}
};

class HiActiveCooling : public BatteryCoolingType
{
    public: 
        HiActiveCooling() : BatteryCoolingType(0, 45) {}
};

class MedActiveCooling : public BatteryCoolingType
{
    public:
        MedActiveCooling() : BatteryCoolingType(0, 40) {}
}; 

class Breach
{
    public:
        BatteryCoolingType *_coolingType = nullptr;
        Breach() = default;
        Breach(BatteryCoolingType *coolingTypeObj) : _coolingType(coolingTypeObj) {}

        BreachType inferBreach(double value, double lowerLimit, double upperLimit);
        BreachType classifyTemperatureBreach(double temperatureInC);
};

