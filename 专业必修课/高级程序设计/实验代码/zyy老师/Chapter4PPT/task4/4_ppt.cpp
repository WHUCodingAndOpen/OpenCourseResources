//  析构函数和带默认参数的构造函数。
//   注意构造函数和析构函数的调用顺序。
#include <iostream>
#include <math.h>
using namespace std;
class Complex // 定义复数类
{
public:
    Complex(double r = 0.0, double i = 0.0); // 带默认参数构造函数的声明
    ~Complex();                              // 析构函数的声明
    double abscomplex();                     // 求复数的模
private:
    double real;
    double imag;
};
Complex::Complex(double r, double i) // 构造函数的实现
{
    cout << "constructing..." << endl;
    real = r;
    imag = i;
    cout << "real:" << real << ",imag:" << imag << endl;
}
Complex::~Complex() // 析构函数的实现
{
    cout << "destructing...";
    cout << "real:" << real << ",imag:" << imag << endl;
}
double Complex::abscomplex() // 成员函数的实现
{
    double t;
    t = real * real + imag * imag;
    return sqrt(t);
}
int main() 		 //主函数
{
    Complex A(1.1, 2.2), B = A;
     //定义复数类对象A，自动调用构造函数
        cout
        << "abs of complex A=" << A.abscomplex() << endl;  // 对象A调用成员函数
    cout << "abs of complex B=" << B.abscomplex() << endl; // 对象B调用成员函数
    return 0;                                              // 在程序结束前自动调用析构函数
}
