#include <iostream>
using namespace std;

class BankTemplateMethod {
public:
    void process(){
        takeNumber();
        transact();
        evaluate();
    }

    virtual void takeNumber() = 0;
    virtual void transact() = 0;
    virtual void evaluate() = 0;
};

class Deposit: public BankTemplateMethod {
public:
    void takeNumber(){
        cout << "Taking customer number" << endl;
    }

    void transact(){
        cout << "Processing deposit" << endl;
    }

    void evaluate(){
        cout << "Evaluating customer" << endl;
    }
};

class Withdraw: public BankTemplateMethod {
public:
    void takeNumber(){
        cout << "Taking customer number" << endl;
    }

    void transact(){
        cout << "Processing withdrawal" << endl;
    }

    void evaluate(){
        cout << "Evaluating customer" << endl;
    }
};

int main(){
    Deposit d;
    Withdraw w;

    d.process();
    w.process();

    return 0;
}