#include <iostream>
using namespace std;

class Product
{
public:
    string content;
    void show()
    {
        cout << "Product: " << content << endl;
    };
};

class Builder
{
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product *getResult() = 0;
};

class ConcreteBuilder : public Builder
{
private:
    Product *product;

public:
    ConcreteBuilder()
    {
        product = new Product();
    }
    void buildPartA()
    {
        product->content += "PartA ";
        cout << "Building Part A" << endl;
    }
    void buildPartB()
    {
        product->content += "PartB ";
        cout << "Building Part B" << endl;
    }
    void buildPartC()
    {
        product->content += "PartC ";
        cout << "Building Part C" << endl;
    }
    Product *getResult()
    {
        return product;
    }
};

class Director
{
private:
    Builder *builder;

public:
    void setBuilder(Builder *b)
    {
        builder = b;
    }
    void construct()
    {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
        builder->buildPartC();
    }
};

int main()
{
    Director *d = new Director();
    Builder *b = new ConcreteBuilder();
    d->setBuilder(b);
    d->construct();
    Product *p = b->getResult();
    p->show();
    return 0;
}