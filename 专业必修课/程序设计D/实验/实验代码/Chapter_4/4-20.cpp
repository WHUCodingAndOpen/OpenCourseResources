#include <iostream>
#include <cmath>

using namespace std;

class Complex{
public:
    Complex() = default;
    Complex(int newR, int newI);
    Complex(double newR);


    void add(Complex &n);
    void show();
    ~Complex() = default;
private:
    double real, imaginary;
};

Complex::Complex(int newR, int newI) : real(newR), imaginary(newI) {}
Complex::Complex(double newR) : real(newR), imaginary(0) {}

void Complex::add(Complex &n){
    real += n.real;
    imaginary += n.imaginary;
}

void Complex::show(){
    cout << real << "+" << imaginary << "i" << endl;
}

int main(){
    Complex c1(3, 5);
    Complex c2 = 4.5;

    c1.add(c2);
    c1.show();

    return 0;
}