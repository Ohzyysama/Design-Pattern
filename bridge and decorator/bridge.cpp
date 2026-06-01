#include <iostream>
#include <string>
using namespace std;

class Color{
public:
    virtual void bepaint(string penType, string name) {};
};

class Red: public Color{
public:
    void bepaint(string penType, string name){
        cout << "Using " << penType << " to paint " << name << " red." << endl;
    }
};

class Blue: public Color{
public:
    void bepaint(string penType, string name){
        cout << "Using " << penType << " to paint " << name << " blue." << endl;
    }
};

class Green: public Color{
public:
    void bepaint(string penType, string name){
        cout << "Using " << penType << " to paint " << name << " green." << endl;
    }
};

class Pen{
protected:
    Color* color;
public:
    void setColor(Color* c){
        color = c;
    }

    virtual void draw(string name) = 0;
};

class SmallPen : public Pen{
public:
    void draw(string name){
        color->bepaint("small", name);
    }
};

class BigPen : public Pen{
public:
    void draw(string name){
        color->bepaint("big", name);
    }
};


int main(){
    Red red;
    Blue blue;
    Green green;

    SmallPen smallPen;
    smallPen.setColor(&red);
    smallPen.draw("rectangle");

    BigPen bigPen;
    bigPen.setColor(&blue);
    bigPen.draw("circle");

    bigPen.setColor(&green);
    bigPen.draw("square");

    return 0;
}