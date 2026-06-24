#include<iostream>
using namespace std;
class Complex{
    private:
        double real;
        double imag;
    public:
        Complex(double real, double imag){
            this->real = real;
            this->imag = imag;
        }
    // Overloading syntax of + operator for addition of imaginary and complex
    friend Complex operator + (const Complex& obj1, const Complex& obj2 ){
        return Complex(obj1.real + obj2.real, obj1.imag + obj2.imag);
    }
    void display(){
        cout<<imag<<" "<<real;
    }
};

int main(){
    Complex c1(1.2,2.3);
    Complex c2(2.3,2.1);
    Complex result = c1 + c2;
    result.display();
}