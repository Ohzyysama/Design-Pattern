#include <iostream>
using namespace std;

class Prototype
{
public:
    virtual Prototype *clone() = 0;
    virtual void print() = 0;
};

class ConcretePrototype : public Prototype
{
public:
    void print()
    {
        cout << "ConcretePrototype" << endl;
    }
    ConcretePrototype *clone()
    {
        return new ConcretePrototype(*this);
    }
};

int main()
{
    ConcretePrototype *prototype = new ConcretePrototype();
    ConcretePrototype *clone = prototype->clone();
    clone->print();
    delete prototype;
    delete clone;
    return 0;
}