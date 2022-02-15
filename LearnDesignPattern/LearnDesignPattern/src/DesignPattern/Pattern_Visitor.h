#pragma once
#include "../Utility/common.h"

class Element;
class VisitorBase
{
public:
    virtual void visit(Element* _ele) = 0;
};

class Element
{
public:
    Element(std::string _str) : m_str(_str)
    {

    }

    virtual void accept(VisitorBase* _visitor) = 0;

    std::string m_str = "this is element";
};

class Element1 : public Element
{
public:
    Element1(std::string _str) : Element(_str)
    {
    }

    void accept(VisitorBase* _visitor) override
    {
        _visitor->visit(this);
    }
};

class Visitor1 : public VisitorBase
{
    void visit(Element* _ele) override
    {
        printf("%s\r\n", _ele->m_str.c_str());
    }
};

void testVisitor()
{
    Element* e1 = new Element1("abc");
    VisitorBase* v1 = new Visitor1();
    e1->accept(v1);
}