#include<iostream>
using namespace std;
class Student{
    private:
        string name;
        int rollNo;
    public:
    Student(string name,int rollNo){
        this->name = name;
        this->rollNo = rollNo;
    }
};
class University{
    private:

    public:
    void Addmission(Student* student){
        cout<<"Student is addmitted";
    }
};
int main(){
    Student* zain = new Student("Ali", 12);
    University VU;
    VU.Addmission(zain);   
    // VU.Addmission();   
}