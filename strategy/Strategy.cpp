#include <iostream>
using namespace std;

class FlyBehaviour
{
public:
    virtual void fly() {};
};

class FlyWithWings : public FlyBehaviour
{
public:
    void fly()
    {
        cout << "I'm flying" << endl;
    }
};

class FlyNoWay : public FlyBehaviour
{
public:
    void fly()
    {
        cout << "I can't fly" << endl;
    }
};

class QuackBehaviour
{
public:
    virtual void quack() {};
};

class Quack : public QuackBehaviour
{
public:
    void quack()
    {
        cout << "Quack" << endl;
    }
};

class Squeak : public QuackBehaviour
{
public:
    void quack()
    {
        cout << "Squeak" << endl;
    }
};

class MuteQuack : public QuackBehaviour
{
public:
    void quack()
    {
        cout << "<<Silence>>" << endl;
    }
};

class Duck
{
    FlyBehaviour *flyBehaviour;
    QuackBehaviour *quackBehaviour;

public:
    void performFly()
    {
        flyBehaviour->fly();
    }

    void performQuack()
    {
        quackBehaviour->quack();
    }

    void setFlyBehaviour(FlyBehaviour *fb)
    {
        flyBehaviour = fb;
    }

    void setQuackBehaviour(QuackBehaviour *qb)
    {
        quackBehaviour = qb;
    }
};

class RubberDuck : public Duck
{
public:
    RubberDuck()
    {
        setFlyBehaviour(new FlyNoWay());
        setQuackBehaviour(new Squeak());
    }
};

class MallardDuck : public Duck
{
public:
    MallardDuck()
    {
        setFlyBehaviour(new FlyWithWings());
        setQuackBehaviour(new Quack());
    }
};

int main()
{

    Duck duck1 = RubberDuck();
    duck1.performQuack();
    duck1.performFly();

    Duck duck2 = MallardDuck();
    duck2.performQuack();
    duck2.performFly();

    return 0;
}