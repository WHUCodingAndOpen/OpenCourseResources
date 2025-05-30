// 对类Point重载“++”（自增）、“--”（自减）运算符，要求同时重载前缀和后缀的形式。
// Same with Lab8_1.cpp
#include <iostream>

class Point {
public:
    // 构造函数
    Point(double x = 0, double y = 0): _x(x), _y(y) {}
    // 获取坐标的函数
    double getX() const { return _x; }
    double getY() const { return _y;}
    // 前缀版本的 "++" 运算符重载
    Point& operator++() {
        ++_x;
        ++_y;
        return *this;
    }
    // 后缀版本的 "++" 运算符重载
    Point operator++(int) {
        Point temp = *this;
        ++_x;
        ++_y;
        return temp;
    }
    // 前缀版本的 "--" 运算符重载
    Point& operator--() {
        --_x;
        --_y;
        return *this;
    }
    // 后缀版本的 "--" 运算符重载
    Point operator--(int) {
        Point temp = *this;
        --_x;
        --_y;
        return temp;
    }
    // 输出Point对象的函数
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.getX() << ", " << point.getY() << ")";
        return os;
    }

private:
    double _x, _y;
};

int main() {
    Point p(1, 1);
    std::cout << "Original point: " << p << std::endl;

    ++p; // 前缀递增
    std::cout << "After prefix ++: " << p << std::endl;

    p++; // 后缀递增
    std::cout << "After postfix ++: " << p << std::endl;

    --p; // 前缀递减
    std::cout << "After prefix --: " << p << std::endl;

    p--; // 后缀递减
    std::cout << "After postfix --: " << p << std::endl;

    return 0;
}