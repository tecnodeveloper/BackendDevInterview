
#include <iostream>
using namespace std;
class User{
    public:
    void getUser(int id){
        cout<<"User is here "<<id<<endl;
    }
    void getUser(string name){
        cout<<"User is here"<<name<<endl;
    }
    void getUser(string name, bool active){
        cout<<"User is here"<<active<<endl;
    }
};    
int main()
{
// Same name but different Parameters
    User Zain;
    Zain.getUser(1);
    Zain.getUser("zain");
    Zain.getUser("zain",true);
}