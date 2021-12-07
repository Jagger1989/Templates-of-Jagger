#pragma once
#include "../common.h"

class Car
{
public:
    void showCar()
    {
        Log::logDebug(m_engin + "\r\n" + m_tire + "\r\n" + m_chassis); 
    }

private:
    std::string m_engin;
    std::string m_tire;
    std::string m_chassis;
};

class BuilderBase
{
public:
    void build()
    {
        buildEngin();
        buildTire();
        buildChassis();
    }

protected:
    virtual void buildEngin() = 0;
    virtual void buildTire() = 0;
    virtual void buildChassis() = 0;
};

class Builder1 : public BuilderBase
{
public:
    void buildEngin()
    {

    }
    void buildTire()
    {

    }
    void buildChassis()
    {

    }

private:
    Car m_car;
};


void testBuilder()
{

}