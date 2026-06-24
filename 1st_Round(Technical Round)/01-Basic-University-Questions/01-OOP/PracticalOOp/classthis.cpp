#include<iostream>
using namespace std;
class Person{
    private:
        string name = "Zain Ali";
        int cnic = 12345;
    public:
        Person(string name, long cnic){
            this->name = name;
            this->cnic = cnic;
        }
};
int main(){
    Person zain("Zain",341011538691);
}