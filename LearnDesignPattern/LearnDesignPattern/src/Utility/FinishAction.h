#pragma once

#include <functional>

class FinishAction
{
private:
    std::function<void()> m_action;

public:
    FinishAction(std::function<void()> _action);

public:
    ~FinishAction();
};