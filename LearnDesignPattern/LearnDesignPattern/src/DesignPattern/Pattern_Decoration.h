#pragma once
#include "common.h"
#include "Log.h"
#include <Windows.h>

// 装饰模式

class Phone
{
public:
    virtual void call() = 0;

    virtual ~Phone() = default;
};

class PhoneA : public Phone
{
public:
    void call() override
    {
        Log::logDebug("PhoneA call");
    }
    ~PhoneA()
    {
        Log::logDebug("~PhoneB");
    }
};

class PhoneB : public Phone
{
public:
    void call() override
    {
        Log::logDebug("PhoneB call");
    }

    ~PhoneB()
    {
        Log::logDebug("~PhoneB");
    }


};

class PhoneC : public Phone
{
public:
    void call() override
    {
        Log::logDebug("PhoneC call");
    }
};

//class PhoneA_Plus : public PhoneA
//{
//public:
//    void call() override
//    {
//        PhoneA::call();
//        // 附加操作
//        plusOperationA();
//    }
//
//private:
//    void plusOperationA()
//    {
//        Log::logDebug("plusOperationA");
//    }
//};
//
//class PhoneB_Plus : public PhoneB
//{
//public:
//    void call() override
//    {
//        PhoneB::call();
//        // 附加操作
//        plusOperationB();
//    }
//
//private:
//    void plusOperationB()
//    {
//        Log::logDebug("plusOperationB");
//    }
//};

// 为了实现PhoneA PhoneB...和PhoneA_Plus PhoneB_Plus...在运行时灵活组合
// 根据注入的Phone实例决定PhoneA PhoneB..., 根据实例化的类型决定PhoneA_Plus PhoneB_Plus ...
// 如何使用继承，每种组合都需要一个派生类，会导致代码剧烈膨胀
class Decoration : public Phone
{
public:
    Decoration(Phone* _phone) : m_phone(_phone)
    {

    }

    void call() override
    {
        this->m_phone->call();
    }

private:
    Phone* m_phone;
};

class PhoneA_Plus : public Decoration
{
public:
    PhoneA_Plus(Phone* _phone) : Decoration::Decoration(_phone)
    {
    }

    void call() override
    {
        Decoration::call();
        plusOperationA();
    }

private:
    void plusOperationA()
    {
        Log::logDebug("plusOperationA");
    }
};

class PhoneB_Plus : public Decoration
{
public:
    PhoneB_Plus(Phone* _phone) : Decoration::Decoration(_phone)
    {
    }

    void call() override
    {
        Decoration::call();
        plusOperationB();
    }

private:
    void plusOperationB()
    {
        Log::logDebug("plusOperationB");
    }
};

void testDecorationMode()
{
    Phone* pA = new PhoneA();
    Phone* pB = new PhoneB();
    Phone* pA_plusA = new PhoneA_Plus(pA);
    Phone* pA_plusB = new PhoneA_Plus(pB);
    Phone* pB_plusA = new PhoneB_Plus(pA);
    Phone* pB_plusB = new PhoneB_Plus(pB);

    ::Sleep(1000);

    pA->call();
    pB->call();
    pA_plusA->call();
    pA_plusB->call();
    pB_plusA->call();
    pB_plusB->call();

    delete pA;
    delete pB;
    delete pA_plusA;
    delete pA_plusB;
    delete pB_plusA;
    delete pB_plusB;
}

// 使用装饰器模式
class Display
{
public:
    virtual unsigned int getRow() = 0;
    virtual unsigned int getColume() = 0;
    virtual std::string getRowText(int _row) = 0;
    virtual ~Display() = default;

    void show()
    {
        for (unsigned int i = 0; i < getRow(); i++)
        {
            Log::logDebug(getRowText(i));
        }
    }
};

class StringDisplay : public Display
{
public:
    StringDisplay(std::string _str) : m_str(_str)
    {
    }

    unsigned int getRow() override
    {
        return 1;
    }

    unsigned int getColume() override
    {
        return m_str.size();
    }

    std::string getRowText(int _row) override
    {
        if (0 == _row)
        {
            return this->m_str;
        }
        return NULL;
    }

private:
    std::string m_str;
};

class Border : public Display
{
public:
    Border(Display* _display) : m_display(_display)
    {
    }

    virtual ~Border() = default;

protected:
    Display* m_display;
};

class SideBorder : public Border
{
public:
    SideBorder(Display* _display, std::string _char)
        : Border(_display)
        , m_borderChar(_char)
    {
    }

    unsigned int getRow() override
    {
        return Border::m_display->getRow();
    }

    unsigned int getColume() override
    {
        return Border::m_display->getColume() + 2;
    }

    std::string getRowText(int _row) override
    {
        return m_borderChar +Border::m_display->getRowText(_row) + m_borderChar;
    }

private:
    std::string m_borderChar;
};

class FullBorder : public Border
{
public:
    FullBorder(Display* _display) : Border(_display)
    {
    }

    unsigned int getRow() override
    {
        return Border::m_display->getRow() + 2;
    }

    unsigned int getColume() override
    {
        return Border::m_display->getColume() + 2;
    }

    std::string getRowText(int _row) override
    {
        if (0 == _row)
        {
            return "+" + makeLine("-", Border::m_display->getColume()) + "+";
        }
        else if (Border::m_display->getRow() + 1 == _row)
        {
            return "+" + makeLine("-", Border::m_display->getColume()) + "+";
        }
        else
        {
            return "|" + Border::m_display->getRowText(_row - 1) + "|";
        }
        return "";
    }

private:
    std::string makeLine(std::string _char, int _count)
    {
        std::string str;
        for (int i = 0; i < _count; i++)
        {
            str += _char;
        }
        return str;
    }
};

void TestDisplay()
{
    Display* b1 = new StringDisplay("Hello world!");
    Display* b2 = new SideBorder(b1, "#");
    Display* b3 = new FullBorder(b2);
    Display* b4 = new FullBorder(b3);
    Display* b5 = new FullBorder(b4);
    b1->show();
    b2->show();
    b3->show();
    b4->show();
    b5->show();
    (new SideBorder(new FullBorder(new SideBorder(new FullBorder(new StringDisplay(std::string("Hello world"))), "*")), "/"))->show();
}