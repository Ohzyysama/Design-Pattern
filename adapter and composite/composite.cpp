#include <iostream>
#include <vector>
using namespace std;

class AbastractComponent{
public:
    virtual void method() = 0;
    virtual void add(AbastractComponent* component) = 0;
    virtual void remove(AbastractComponent* component) = 0;
    virtual AbastractComponent* get(int index) = 0;
};

class File : public AbastractComponent{
public:
    void method(){
        cout << "File method called" << endl;
    }

    void add(AbastractComponent* component){}
    void remove(AbastractComponent* component){}
    AbastractComponent* get(int index){return nullptr;}

};

class Folder : public AbastractComponent{ 
    vector<AbastractComponent*> components;
public:
    void method(){
        cout << "Folder method called" << endl;
        for(int i = 0; i < components.size(); i++){
            components[i]->method();
        }
    }

    void add(AbastractComponent* component){
        components.push_back(component);
    }

    void remove(AbastractComponent* component){
        for(int i = 0; i < components.size(); i++){
            if(components[i] == component){
                components.erase(components.begin() + i);
                return;
            }
        }
    }
    
    AbastractComponent* get(int index){
        if(index < components.size()){
            return components[index];
        }
        return nullptr;
    }
};

int main(){
    AbastractComponent* folder = new Folder();
    AbastractComponent* file = new File();
    folder->add(file);
    folder->method();
    delete folder;
    delete file;    
    return 0;
}