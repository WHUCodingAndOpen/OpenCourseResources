// 请编写一个抽象类Shape，在此基础上派生出类Rectangle和Circle
// 二者都有计算对象面积的函数getArea()、计算对象周长的函数getPerim()
#include <iostream>
#include <cmath>
const double PI = 3.141592635897;

// 抽象基类 Shape
class Shape {
public:
    // 纯虚函数，用于计算面积
    virtual double getArea() const = 0;
    // 纯虚函数，用于计算周长
    virtual double getPerim() const = 0;
    // 虚析构函数
    virtual ~Shape() {}
};
// 派生类 Rectangle
class Rectangle : public Shape {
public:
    // 构造函数
    Rectangle(double length = 0.0, double width = 0.0) : length(length), width(width) {}
    // 计算面积
    double getArea() const override {
        return length * width;
    }
    // 计算周长    
    double getPerim() const override {
        return 2 * (length + width);
    }
private:
    double length, width;
};
// 派生类 Circle
class Circle : public Shape {
public:
    // 构造函数
    Circle(double r) : radius(r) {}
    // 计算面积
    double getArea() const override {
        return PI * radius * radius;
    }
    // 计算周长
    double getPerim() const override {
        return 2 * PI * radius;
    }
private:
    double radius;
};

int main() {

    Rectangle rect(10.0, 5.0);
    Circle circ(7.0);

    // 计算并输出矩形的面积和周长
    std::cout << "Rectangle area: " << rect.getArea() << std::endl;
    std::cout << "Rectangle perimeter: " << rect.getPerim() << std::endl;

    // 计算并输出圆形的面积和周长
    std::cout << "Circle area: " << circ.getArea() << std::endl;
    std::cout << "Circle perimeter: " << circ.getPerim() << std::endl;

    return 0;
}