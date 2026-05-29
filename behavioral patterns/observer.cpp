#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MyObserver
{
public:
    virtual void response() = 0;
};

class MySubject
{
protected:
    vector<MyObserver *> observers;

public:
    void attach(MyObserver *obs)
    {
        observers.push_back(obs);
    }

    void detach(MyObserver *obs)
    {
        observers.erase(find(observers.begin(), observers.end(), obs));
    }

    virtual void cry() = 0;
};

class Cat : public MySubject
{
public:
    void cry()
    {
        for (auto obs : observers)
        {
            obs->response();
        }
    }
};

class Mouse : public MyObserver
{
public:
    void response()
    {
        cout << "I am mouse, I am watching you!" << endl;
    }
};

class Dog : public MyObserver
{
public:
    void response()
    {
        cout << "I am dog, I am watching you!" << endl;
    }
};

int main()
{

    Cat cat;
    Mouse mouse;
    Dog dog;
    cat.attach(&mouse);
    cat.attach(&dog);
    cat.cry();
    cat.detach(&dog);
    cat.cry();

    return 0;
}