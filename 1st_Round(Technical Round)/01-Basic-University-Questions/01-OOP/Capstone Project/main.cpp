#include<iostream>
#include<string>
#include <SQLiteCpp/SQLiteCpp.h>

using namespace std;

class Admin{
    private:
        string name = "Zain Ali";
        string password;
    public:
         void getPassword(){
            cout<<"\n Enter your password to acccess portal \n";
            cin>>password;
            if(password == "admin12345")
            {
                showDashboard();
                cout<<"Admin dashboard";

            }
            else{
                int count = 3;
                for (int i = 1; i <= count; count--) {
                    cout<<"\n Wrong Password, Try again "<<count<<" attempt left \n";
                    cin>>password;
                    if(password == "admin12345")
                    {
                        showDashboard();
                        cout<<"Admin dashboard";
                        break;
                       }
                }                       
            }
           
        }
        void showDashboard(){
            int dashboardinput = 0;
            cout<<"Press 1 to 'SignUp User' \n";
            cout<<"Press 2 to 'Insert Book' \n";
            cout<<"Press 3 to 'Update User' \n";
            cout<<"Press 3 to 'Update Book' \n";
            cout<<"Press 5 to 'Go Back' \n";
            cin>>dashboardinput;
            int i = 1;
            while (i != 0) {
                if(dashboardinput == 1 || dashboardinput == 2 || dashboardinput == 3|| dashboardinput == 4 || dashboardinput == 5){
                if(dashboardinput == 1){
                cout<<"\n Signup Form";
                cout<<"Register user";
                i = 0;
            }else if(dashboardinput == 2){
                cout<<"\n Insert Book";
                i = 0;
            }else if(dashboardinput == 3){
                cout<<"\n Update User";
                i = 0;
            }else if(dashboardinput == 4){
                cout<<"\n Update Book";
                i = 0;
            }
            else{
                cout<<"\n Go Back";
                i = 0;
                cout<<"\n Go one step back";
            }
        }
        else{
           cout<<"\nPress any number 1, 2, 3, 4, 5 to choose option";
           cin>>dashboardinput;
        }
        }
    }
};
class User{
    private:
    string email;
    string password;
    public:

    void getEmail(){
        cout<<"\n Enter your Email \n";
        cin>>email;
        if(password == "user@gmail.com")
        {
            getUserPassword();

        }
        else{
            int count = 3;
            for (int i = 1; i <= count; count--) {
                cout<<"\n Wrong Email, Try again "<<count<<" attempt left \n";
                cin>>email;
                if(email == "admin12345")
                {
                    getUserPassword();
                    break;
                   }
            }                       
        }
       
    }
    }
    void getUserPassword(){
        cout<<"\n Enter your password \n";
        cin>>password;
        if(password == "user12345")
        {
            showUserDashboard();

        }
        else{
            int count = 3;
            for (int i = 1; i <= count; count--) {
                cout<<"\n Wrong Password, Try again "<<count<<" attempt left \n";
                cin>>password;
                if(password == "admin12345")
                {
                    showUserDashboard();
                    cout<<"Admin dashboard";
                    break;
                   }
            }                       
        }
       
    }
    void showUserDashboard(){
        int dashboardinput = 0;
        cout<<"Press 1 to 'Borrow Book' \n";
        cout<<"Press 2 to 'Search Book' \n";
        cout<<"Press 3 to 'Go Back' \n";
        cin>>dashboardinput;
        int i = 1;
        while (i != 0) {
            if(dashboardinput == 1 || dashboardinput == 2 || dashboardinput == 3){
            if(dashboardinput == 1){
            cout<<"\n Borrow Form";
            cout<<"\n Borrowed Book";
            i = 0;
        }else if(dashboardinput == 2){
            cout<<"\n Search Book";
            i = 0;
        else{
            cout<<"\n Go Back";
            i = 0;
            cout<<"\n Go one step back";
        }
    }
}
    else{
       cout<<"\nPress any number 1, 2, 3 to choose option";
       cin>>dashboardinput;
    }
    }

};

class Dashboard{
    private:
    public:
    
};
int main(){
    for(int i = 1; i < 5;i++){
        cout<<"---------------------------------------------------------------\n";
    }
    cout<<"--------<<<< Welcome to libraryManagementSystem >>>>-----------\n";
    for(int i = 1; i < 5;i++){
        cout<<"---------------------------------------------------------------\n";
    }
    int dashboardinput = 0;
    cout<<"Press 1 to 'Login as Admin' \n";
    cout<<"Press 2 to 'Login as User' \n";
    cout<<"Press 3 to 'Exit Program' \n";
    cin>>dashboardinput;
    int i = 1;
    while (i != 0) {
        if(dashboardinput == 1 || dashboardinput == 2 || dashboardinput == 3){
            if(dashboardinput == 1){
                cout<<"\n Welcome admin";
                Admin a;
                a.getPassword();
                i = 0;
            }else if(dashboardinput == 2){
                cout<<"\n Welcome user";
                User u;
                u.getPassword();
                i = 0;
            }else{
                cout<<"\n Exit program! GoodBye";
                i = 0;
                return 0;
            }
        }else{
           cout<<"\nPress any number 1, 2, 3 to choose option";
           cin>>dashboardinput;
        }
    }
}