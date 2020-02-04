#ifndef _OBSERVER_H_
#define _OBSERVER_H_

// 抽象观察者
class IObserver
{
public:
    virtual void Update(float price) = 0;  // 更新价格
};


#endif // _OBSERVER_H_