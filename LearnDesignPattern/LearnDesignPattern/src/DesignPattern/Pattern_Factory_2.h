#pragma once
#include "common.h"


class CarBase
{
public:
    virtual void printType() = 0;

    virtual ~CarBase() = default;
};

class BusinessCarBase : public CarBase
{
public:
    void printType()
    {
        Log::logDebug("BusinessCar");
    }
};

class SportCarBase : public CarBase
{
public:
    void printType()
    {
        Log::logDebug("SportCarBase");
    }
};

class BenzBusinessCar : public BusinessCarBase
{

};

class BydBusinessCar : public BusinessCarBase
{

};

class BenzSportCar : public SportCarBase
{

};

class BydSportCar : public BusinessCarBase
{

};


void testFactory()
{

}
