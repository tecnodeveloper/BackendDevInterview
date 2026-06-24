#include<iostream>
using namespace std;
class Person{
    private:
        string name;
        int cnic;
    public:
    static void display1(string name){
        // this->name = name;
        name = name;
        cout<<"name is "<<name<<endl;
    }
    void display(){
        cout<<"Name is "<<name;
    }
};
int main(){
    // Person p1;
    Person::display1("Zain");
    // Person::display();
}