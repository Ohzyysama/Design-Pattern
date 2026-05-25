#include <iostream>
using namespace std;

class Button
{
public:
    virtual void click() {};
};

class RectangleButton : public Button
{
public:
    void click()
    {
        cout << "Rectangle Button Clicked" << endl;
    }
};

class CircleButton : public Button
{
public:
    void click()
    {
        cout << "Circle Button Clicked" << endl;
    }
};

class Factory
{
public:
    virtual Button *createButton() = 0;
};

class RectangleFactory : public Factory
{
public:
    Button *createButton()
    {
        return new RectangleButton();
    }
};

class CircleFactory : public Factory
{
public:
    Button *createButton()
    {
        return new CircleButton();
    }
};

int main()
{
    Factory *factory = new RectangleFactory();
    Button *button = factory->createButton();
    button->click();

    factory = new CircleFactory();
    button = factory->createButton();
    button->click();

    delete factory;
    delete button;

    return 0;
}