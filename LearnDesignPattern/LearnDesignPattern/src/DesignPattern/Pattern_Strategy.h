#pragma once

class I_Func
{
public:
    virtual int calculate() = 0;
    virtual ~I_Func() = default;
};

class FuncA : public I_Func
{
public:
    int calculate() override
    {

    }
};

class FuncB : public I_Func
{
public:
    int calculate() override
    {

    }
};

class Test
{
public:
    Test(I_Func* _func_ptr) : m_func_ptr(_func_ptr) {}

    virtual ~Test()
    {
        if (nullptr != m_func_ptr)
        {
            delete m_func_ptr;
            m_func_ptr = nullptr;
        }
    }
    
    int calculate()
    {
        return m_func_ptr->calculate();
    }

private:
    I_Func * m_func_ptr;
};

void testStrategyMode()
{
    Test obj(new FuncA());
    obj.calculate();
    Test obj2(new FuncB());
    obj2.calculate();
}