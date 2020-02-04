#include "concrete_subject.h"
#include "concrete_observer.h"

int main()
{
    // 创建主题、观察者
    ConcreteSubject *pSubject = new ConcreteSubject();
    IObserver *pObserver1 = new ConcreteObserver("Jack Ma");
    IObserver *pObserver2 = new ConcreteObserver("Pony");
    IObserver *pObserver3 = new ConcreteObserver("Yansong Li");

    // 注册观察者
    pSubject->Attach(pObserver1);
    pSubject->Attach(pObserver2);
    pSubject->Attach(pObserver3);

    // 更改价格，通知观察者
    pSubject->SetPrice(12.5);
    pSubject->Notify();
    cout << "===========================" << endl;

    // 注销观察者
    pSubject->Detach(pObserver3);

    // 更加价格，通知观察者
    pSubject->SetPrice(15.0);
    pSubject->Notify();

    return 0;
}