#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
    void show() {
        cout << real << "+" << imag << "i" << endl;
    }
    Complex operator=(double d) {
        real = d;
        imag = 0;
        return *this;
    }
    
    void add(const Complex &c) {
        *this = *this + c ;
    }
};

int main(){
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
};