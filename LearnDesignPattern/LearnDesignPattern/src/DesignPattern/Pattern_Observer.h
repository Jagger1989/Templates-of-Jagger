#pragma once

#include "common.h"

class Notify
{
protected:
    class NotifyListener
    {
    public:
        explicit NotifyListener(const std::string &_mark) : m_uniqueMark(_mark) {}
        virtual ErrorCode onInvoke(const std::string &_name, const std::string &_type, const std::string &_val) = 0;
        virtual ~NotifyListener() = default;

        std::string getMark()
        {
            return this->m_uniqueMark;
        }

    private:
        const std::string m_uniqueMark;
    };

    Notify()
    {
        this->m_notifyListeners.clear();
    }

    virtual ~Notify() = default;

    // 订阅通知
    ErrorCode addListener(NotifyListener* _listener)
    {
        if (_listener == nullptr)
        {
            Log::logDebug("Listener is null");
            return RET_ERROR;
        }
        std::string mark = _listener->getMark();
        auto index = m_notifyListeners.find(mark);
        if (index != m_notifyListeners.end())
        {
            Log::logDebug("Duplicate listener");
            return RET_ERROR;
        }
        m_notifyListeners.insert(std::make_pair(mark, _listener));
        return RET_SUCCESS;
    }

    ErrorCode removeListener(NotifyListener* _listener)
    {
        if (nullptr == _listener) {
            Log::logDebug("Listener is null");
            return RET_ERROR;
        }
        auto index = m_notifyListeners.find(_listener->getMark());
        if (index != m_notifyListeners.end()) {
            m_notifyListeners.erase(index);
        }
        return RET_SUCCESS;
    }

    // 通知
    void dispatchNotify(const std::string &_name, const std::string &_type, const std::string &_val)
    {
        int cout = 0;
        for (auto it = m_notifyListeners.begin(); it != m_notifyListeners.end(); it++)
        {
            NotifyListener* listener = it->second;
            if (nullptr != listener)
            {
                listener->onInvoke(_name, _type, _val);
                ++cout;
            }
        }
        Log::logDebug("Notify number = " + cout);
    }

    void clear()
    {
        m_notifyListeners.clear();
        Log::logDebug("Listener number = " + m_notifyListeners.size());
    }

private:
    std::map<std::string, NotifyListener*> m_notifyListeners;

};