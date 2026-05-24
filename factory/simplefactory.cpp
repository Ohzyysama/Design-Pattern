#include <iostream>
using namespace std;

class Product
{
public:
    virtual void revealType() {};
};

class ConcreteProduct1 : public Product
{
public:
    void revealType()
    {
        cout << "I am ConcreteProduct1" << endl;
    }
};

class ConcreteProduct2 : public Product
{
public:
    void revealType()
    {
        cout << "I am ConcreteProduct2" << endl;
    }
};

class Factory
{
public:
    Product* factoryMethod(string type)
    {
        if (type == "Product1")
        {
            return new ConcreteProduct1();
        }
        else if (type == "Product2")
        {
            return new ConcreteProduct2();
        }
        else
        {
            return new Product();
        }
    }
};

int main()
{
    Factory factory;
    Product* product = factory.factoryMethod("Product1");
    product->revealType();
    delete product;
    return 0;
}