#pragma once
#include "../Utility/common.h"

enum Type{
    A,
    A_PLUS,
    B,
    B_PLUS
};

class Product{};

class ProductA : public Product{};

class ProductB : public Product{};

// 简单工厂模式
// 有新产品需要修改工厂类
class Factory
{
public:
    Product* create(const Type &_type)
    {
        switch (_type)
        {
        case A:
            return new ProductA();
            break;
        case A_PLUS:
            break;
        case B:
            return new ProductB();
            break;
        case B_PLUS:
            break;
        default:
            break;
        }
        return nullptr;
    }
};

// 工厂模式
// 有新产品只需要增加工厂类，但是如果A有多种A，B有多种B就无法满足，需要使用抽象工厂模式
class I_Factory
{
public:
    virtual Product* create() = 0;
};

class FactoryA : public I_Factory
{
public:
    Product* create() override
    {
        return new ProductA();
    }
};

class FactoryB : public I_Factory
{
public:
    Product* create() override
    {
        return new ProductB();
    }
};

// 抽象工厂模式
class ProductA1 : public ProductA{};

class ProductA2 : public ProductA{};

class ProductB1 : public ProductB{};

class ProductB2 : public ProductB{};

class I_Factory_I
{
public:
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class Factory1 : public I_Factory_I
{
public:
    ProductA* createProductA() override
    {
        return new ProductA1();
    }
    ProductB* createProductB() override
    {
        return new ProductB1();
    }
};

class Factory2 : public I_Factory_I
{
public:
    ProductA* createProductA() override
    {
        return new ProductA2();
    }
    ProductB* createProductB() override
    {
        return new ProductB2();
    }
};
// 使用模板实现工厂方法？
class CarBase
{

};

class CarBenz : public CarBase
{
public:
    void printT()
    {
        Log::logDebug("printT");
    }
};

class CarByd : public CarBase
{
};

class STCarFactory
{
public:
    template<class T>
    static T* create()
    {
        return new T();
    }
};

#if 0
// 此种版本限定了T是CarBase的子类
class STCarBaseFactory
{
public:
    template<class T>
    static CarBase* create()
    {
        return new T();
    }
};
#endif

void testFactory()
{
    I_Factory* ptr = new FactoryA();
    Product* pA = ptr->create();

    I_Factory_I* ptr2 = new Factory1();
    I_Factory_I* ptr3 = new Factory2();
    ProductA* pa1 = ptr2->createProductA();
    ProductA* pa2 = ptr3->createProductA();
    CarBase* carBenz = STCarFactory::create<CarBenz>();
}
