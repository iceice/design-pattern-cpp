---
title: 每日一个设计模式之策略模式
comments: true
mathjax: false
date: 2019-12-28 10:09:18
categories:
- 设计模式
- 技术笔记
tags:
- 设计模式
---

> Strategy Pattern 策略模式，属于行为型模式。策略对应到计算机的世界当中就是算法，所以策略模式就是对算法的封装，把一系列的算法分别封装到对应的类中，使他们可以相互替换。

<!-- more -->

### 1. UML图

![Strategy](每日一个设计模式之策略模式/Strategy.png)

通过上面的图，我们可以通过 Context 类的构造函数传参，调用 StrategyA、StrategyB、StrategyC 三种策略（算法）。定义了 `Strategy` 基类，通过虚函数继承的方式实现了多态。

### 2. 应用场景

可能你已经感觉到了策略模式和简单工厂模式十分的相似，那么我们什么时候决定使用策略模式呢？

我们首先回顾一下简单工厂模式的工作原理，它是通过工厂函数创建了一个指向对应类的指针，并且把这个指针返回给客户端。所以客户端需要和：工厂对象、实例对象。这两种对象进行交互。

当我们使用策略模式的时候，客户端只需要和 Context 这一个类进行交互就可以了，降低了耦合度。

另外一个区分点就是，我们只要在分析过程中听到需要在**不同时间应用不同的业务规则**，就可以考虑使用策略模式。如果，我们需要根据**不同的时间应用不同的对象**，就要考虑简单工厂模式。

策略模式还有一个优点就是简化了单元测试，因为每个算法都有自己的类，可以通过自己的接口单独测试。

### 3. 代码

```c++
#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <string>
#include "strategy.h"

class Context
{
    private:
    CashSuper *cs;

    public:
    Context(std::string type);

    double GetResult(double money);
};

Context::Context(std::string type)
{
    // Imitated Simple Factory
    if (type == "normal")
        cs = new CashNormal();
    else if (type == "rebate-8")
        cs = new CashRebate(0.8);
    else if (type == "return-300-100")
        cs = new CashReturn(300, 100);
}

double Context::GetResult(double money)
{
    return cs->acceptCash(money);
}

#endif // _CONTEXT_H_
```

```c++
#ifndef _STRATEGY_H_
#define _STRATEGY_H_

// Abstract base class
class CashSuper
{
public:
    virtual double acceptCash(double money) = 0;
};

// This Class is a normal cash.
class CashNormal : public CashSuper
{
public:
    double acceptCash(double money) { return money; }
};

// This Class is a rebate cash according to specified rebate.
class CashRebate : public CashSuper
{
public:
    CashRebate(double r) : _rebate(r) {}

    double acceptCash(double money) { return money * _rebate; }

private:
    double _rebate;
};

// this Class is a full reduction cash.
class CashReturn : public CashSuper
{
public:
    CashReturn(int c, int r) : _condition(c), _return(r) {}

    double acceptCash(double money)
    {
        double ans = money;
        if (money >= _condition)
            ans -= money / _condition * _return;
        return ans;
    }

private:
    double _condition;
    double _return;
};

#endif // _STRATEGY_H_
```

### 4. 缺点

- 客户端必须知道所有的策略类，并自行决定使用哪一个策略类。
- 策略模式将造成产生很多策略类