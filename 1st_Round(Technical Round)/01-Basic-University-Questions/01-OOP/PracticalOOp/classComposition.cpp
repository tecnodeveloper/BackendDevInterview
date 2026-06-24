#include<iostream>
using namespace std;
class Engine{
    public:
        void getEngine(){
            cout<<"Engine is start";
        }
    };
class Car{
    private:
        Engine engine;
public:
    void startCar(){
        cout<<"Starting car require engine class";
        engine.getEngine();
    }
};

int main(){
    Car mehran;
    mehran.startCar();
}