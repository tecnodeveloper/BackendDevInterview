#include<iostream>
using namespace std;
class Person{
    private:
        string name;
        int cnic;
    public:
    Person(string name, int cnic){
        this->name = name;
        this->cnic = cnic;
    }
    virtual void talk(){
        cout<<"Person can talk "<<endl;
    }
};
class Zain{
private:
public:
    void talk(){
        cout<<"Zain can talk in punjabi and urdu";
    }
};
int main(){
    Zain ali;
    ali.talk();
}