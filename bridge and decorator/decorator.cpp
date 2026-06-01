#include <iostream>
#include <string>
using namespace std;

class Beverage {
    string description;
public:
    virtual string getDescription() = 0;
    virtual double cost() = 0;
};

class Espresso : public Beverage {
public:
    string getDescription() { return "Espresso"; }
    double cost() { return 1.99; }
};

class HouseBlend : public Beverage {
public:
    string getDescription() { return "House Blend Coffee"; }
    double cost() { return 0.89; }
};

class CondimentDecorator : public Beverage {
public:
    virtual string getDescription() = 0;
};

class Mocha : public CondimentDecorator {
    Beverage* beverage;
public:
    Mocha(Beverage* b) { beverage = b; }
    string getDescription() { return beverage->getDescription() + ", Mocha"; }
    double cost() { return beverage->cost() + 0.20; }
};

class Soy : public CondimentDecorator {
    Beverage* beverage;
public:
    Soy(Beverage* b) { beverage = b; }
    string getDescription() { return beverage->getDescription() + ", Soy"; }
    double cost() { return beverage->cost() + 0.15; }
};

class Whip : public CondimentDecorator {
    Beverage* beverage;
public:
    Whip(Beverage* b) { beverage = b; }
    string getDescription() { return beverage->getDescription() + ", Whip"; }
    double cost() { return beverage->cost() + 0.10; }
};

int main() {
    Beverage* beverage = new Espresso();
    cout << beverage->getDescription() << " $" << beverage->cost() << endl;

    Beverage* beverage2 = new HouseBlend();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;
    return 0;
}