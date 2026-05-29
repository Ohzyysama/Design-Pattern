#include <iostream>
#include <string>
using namespace std;

class DataOperator{
    string password;
public:
    void setPassword(string pwd){
        password = pwd;
    }
    string getPassword(){
        return password;
    }
    virtual string doEncrypt(int key, string ps) = 0;
};

class Caesar{
public:
    string encrypt(int key,string ps){
         string encrypted = "";
        for(char c: ps){
            encrypted += char(c + key);
        }
        return encrypted;
    }
};

class CipherAdapter: public DataOperator{
    Caesar* cipher;
public:
    CipherAdapter(){
        cipher = new Caesar();
    }
    string doEncrypt(int key, string ps){
        return cipher->encrypt(key,ps);
    }
};

int main(){ 
    DataOperator* op = new CipherAdapter();
    op->setPassword("<PASSWORD>");
    cout << op->getPassword() << endl;
    cout << op->doEncrypt(5,op->getPassword()) << endl;
}