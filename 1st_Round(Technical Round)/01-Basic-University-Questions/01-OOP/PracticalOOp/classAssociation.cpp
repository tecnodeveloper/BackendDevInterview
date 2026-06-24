#include<iostream>
using namespace std;
class Account{
    private:
        int id;
        double money;
    public:
    Account(int id, double money){
        this->id = id;
        this->money = money;
    }
    int getId(){
        return id;
    }
    double getMoney(){
        return money;
    }
};
class Bank{
    private:
    public:
        void getMoney(Account* fromAccount, Account* toAccount, double amount){
            cout<<"You have successfully withdraw money"<<endl;
        }
};

int main(){
    Account* account1 = new Account(1,1200);
    Account* account2 = new Account(2,1200);
    Bank meezan;
    meezan.getMoney(account1,account2,120);
    return 0;
}