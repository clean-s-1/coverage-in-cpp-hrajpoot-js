#include <bits/stdc++.h>
#include "typewise-alert.h"

class CollingType
{
    private:
        int _lowerLimit;
        int _upperLimit;
    public:
        CollingType(int lowerLimit, int upperLimit) : _lowerLimit(lowerLimit), _upperLimit(upperLimit) {}

        int fetchLowerLimit();
        int fetchUpperLimit();
};

class PassiveColling : public CollingType
{
    public:
       PassiveColling() : CollingType(0, 35) {}
};

class HiActiveColling : public CollingType
{
    public: 
        HiActiveColling() : CollingType(0, 45) {}
};

class MedActiveColling : public CollingType
{
    public:
        MedActiveColling() : CollingType(0, 40) {}
}; 

class Breach
{
    private:
        CollingType *_collingType = nullptr;
    public:
        Breach() = default;
        Breach(CollingType *collingType) : _collingType(collingType) {}

        BreachType inferBreach(double value, double lowerLimit, double upperLimit);
        BreachType classifyTemperatureBreach(double temperatureInC);
};

