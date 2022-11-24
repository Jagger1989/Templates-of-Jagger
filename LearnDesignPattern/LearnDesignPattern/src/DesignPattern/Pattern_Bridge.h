#pragma once
#include "common.h"

class Engin
{
public:
    virtual void installEngin() = 0;
    virtual ~Engin() = default;
};

class Car
{
public:
    Car(Engin* _engin) : m_engin(_engin)
    {

    }

    virtual void installEngin() = 0;

    virtual ~Car() = default;

protected:
    Engin* m_engin;
};

class CarBenz : public Car
{
public:
    CarBenz(Engin* _engin) : Car(_engin)
    {

    }

    void installEngin()
    {
        Car::m_engin->installEngin();
    }
};

class CarBYD : public Car
{
public:
    CarBYD(Engin* _engin) : Car(_engin)
    {

    }

    void installEngin()
    {
        Car::m_engin->installEngin();
    }
};

class EnginEA888 : public Engin
{
public:
    void installEngin()
    {
        Log::logDebug("Installed EnginEA888");
    }
};

class EnginEA777 : public Engin
{
public:
    void installEngin()
    {
        Log::logDebug("Installed EnginEA777");
    }
};

void testBridge()
{
    Engin* ea888 = new EnginEA888();
    Engin* ea777 = new EnginEA777();
    Car* carBenz = new CarBenz(ea888);
    Car* carBYD = new CarBYD(ea777);

    carBenz->installEngin();
    carBYD->installEngin();
}
