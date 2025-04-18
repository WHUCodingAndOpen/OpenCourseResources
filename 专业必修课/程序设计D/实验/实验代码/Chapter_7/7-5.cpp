// 7-5
// 定义一个基类Shape，在此基础上派生出 Rectangle 和 Circle,两者带有getAera()函数计算对象的面积。
// 使用 Rectangle 类创建一个派生类 Square().

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592635897;

class Shape {
public:
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double getArea() const {
        return width * height;
    }

private:
    double width;
    double height;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double getArea() const {
        return PI * radius * radius;
    }

private:
    double radius;
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {} 
};

int main() {
    Rectangle rectangle(5.0, 4.0);
    cout << "Rectangle area: " << rectangle.getArea() << endl;

    Circle circle(3.0);
    cout << "Circle area: " << circle.getArea() << endl;

    Square square(4.0);
    cout << "Square area: " << square.getArea() << endl;

    return 0;
}