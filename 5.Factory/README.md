> 工厂模式 (Factory Pattern) 属于创建型模式，它提供了一种创建对象的最佳方式。在工厂模式中，我们在创建对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的对象。

<!-- more -->

### 1. UML图

![image-20200121103948074](每日一个设计模式之工厂模式/image-factory.png)

我们可以看到工厂模式与简单工厂模式的区别在于，工厂模式多了一个 Factory 基类，通过继承的方法对每一个运算操作都设计了一个工厂类专门生产唯一的运算操作。那么这样做有什么好处呢？假如我们现在需要增加一个乘方的操作，如果是简单工厂模式的话，我们需要**更改工厂类中的case判断语句**，这也正好是简单工厂模式的最大优点 **“在工厂类中包含必要的逻辑判断，根据客户端的选择条件动态实例化相关的类”**。而简单工厂模式存在的问题也恰恰就在这里，我们修改原有的工厂类就等同于我们不但对扩展开放了，对修改也开放了，这就违背了 **开放封闭原则**。

然后，再看上面的工厂模式由于定义了一个用于创建对象的接口，让子类决定实例化哪一个类，使一个类的实例化延迟到了它的子类。因为无论我们创建加减乘除中的哪一个方法，他们都可以抽象为一个相同的方法，既然这个工厂类与分支耦合，那么我们就对它下手，根据依赖倒转原则，我们把工厂类抽象出一个接口，然后不同的子类根据自己的类型，实现这个接口。这样，当我们增加一个运算操作的时候，只需要增加一个运算类和一个工厂类就可以了，原有的代码不需要改动。这就完全符合了开放-封闭原则的精神。

### 2. 源码

```c++
class LeiFeng
{
protected:
    std::string _volunteer_t;
public:
    LeiFeng(std::string type) : _volunteer_t(type) {}
    ~LeiFeng() {}
    
    void Sweep()
    {
        std::cout << "扫地的" << _volunteer_t << std::endl;
    }

    void Wash()
    {
        std::cout << "洗衣的" << _volunteer_t << std::endl;
    }

    void Buy()
    {
        std::cout << "买菜的" << _volunteer_t << std::endl;
    }
};

class Student : public LeiFeng
{
public:
    Student() : LeiFeng::LeiFeng("学生志愿者") {}
    ~Student() {}
};

class Volunteer : public LeiFeng
{
public:
    Volunteer() : LeiFeng::LeiFeng("社区志愿者") {}
};
```

```c++
// 简单工厂模式
class SimpleFactory
{
public:
    static LeiFeng* CreateLeiFeng(std::string type)
    {
        LeiFeng* lf = nullptr;
        if (type == "学生志愿者") lf = new Student();
        else if (type == "社区志愿者") lf = new Volunteer();
        return lf;
    }
};

/* --------- 客户端 --------- */
LeiFeng* student1 = SimpleFactory::CreateLeiFeng("学生志愿者");  // 修改处
LeiFeng* student2 = SimpleFactory::CreateLeiFeng("学生志愿者");  // 修改处
LeiFeng* student3 = SimpleFactory::CreateLeiFeng("学生志愿者");  // 修改处
student1->Buy();
student2->Sweep();
student3->Wash();
```

```c++
// 工厂模式
class IFactory
{
public:
    IFactory() {}
    virtual ~IFactory() {}
    virtual LeiFeng *CreateLeiFeng() = 0;
};

class StudentFactory : public IFactory
{
public:
    LeiFeng *CreateLeiFeng() { return new Student(); }
};

class VolunteerFactory : public IFactory
{
public:
    LeiFeng *CreateLeiFeng() { return new Volunteer(); }
};

/* --------- 客户端 --------- */
IFactory *factory = new VolunteerFactory();  // 修改处
LeiFeng *volunteer1 = factory->CreateLeiFeng();
LeiFeng *volunteer2 = factory->CreateLeiFeng();
LeiFeng *volunteer3 = factory->CreateLeiFeng();
volunteer1->Buy();
volunteer2->Sweep();
volunteer3->Wash();
```

通过上面的代码我们可以看到，当我们需要要从学生志愿者切换到社区职员制的时候，工厂模式只需要修改一处代码：更换一个工厂即可。但是简单工厂模式就需要修改三处代码，因为我们需要传递一个 `type` 类型到简单工厂的内部提供判断逻辑。

### 3. 优点和缺点

**优点**

工厂模式克服了简单工厂模式违背开放-封闭原则的缺点，又保持了封装对象创建过程的优点，使得更换对象时，不需要做大的改动就可以实现，降低了客户程序与产品对象的耦合。

**缺点**

每增加一个产品，就需要增加一个产品工厂的类，增加了额外的代码量，使得系统冗杂。

