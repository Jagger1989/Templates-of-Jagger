#include "FinishAction.h"

FinishAction::FinishAction(std::function<void()> _action) : m_action(_action)
{}

FinishAction::~FinishAction()
{
    m_action();
}
