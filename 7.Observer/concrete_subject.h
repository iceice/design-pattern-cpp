#ifndef _CONCRETE_SUBJECT_H_
#define _CONCRETE_SUBJECT_H_

#include "subject.h"
#include "observer.h"
#include <iostream>
#include <list>

using namespace std;

// 具体主题
class ConcreteSubject : public ISubject
{
private:
    list<IObserver*> _observers;
    float _price;
public:
    ConcreteSubject() : _price(10) {}

    void SetPrice(float p) { _price = p; }

    // 增加一个观察者
    void Attach(IObserver *observer)
    {
        _observers.push_back(observer);
    }

    // 移除一个观察者
    void Detach(IObserver *observer)
    {
        _observers.remove(observer);
    }

    // 通知所有观察者
    void Notify()
    {
        for (auto it = _observers.begin(); it != _observers.end(); ++it)
            (*it)->Update(_price);
    }
};

#endif // _CONCRETE_SUBJECT_H_