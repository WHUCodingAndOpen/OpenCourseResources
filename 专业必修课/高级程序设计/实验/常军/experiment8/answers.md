# 第八章

## 8-6

请编写一个抽象类Shape，在此基础上派生出类Rectangle和Circle，二者都有计算对象面积的函数getArea()、计算对象周长的函数getPerim()。  

源码：

```cpp
#include <bits/stdc++.h>

class Shape
{
public:
    virtual double getArea() = 0;
    virtual double getPerim() = 0;
};

class Rectangle : public Shape
{
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {};

    double getArea()
    {
        return length * width;
    };

    double getPerim()
    {
        return 2 * (length + width);
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea()
    {
        return  3.14159265 * radius * radius;
    };

    double getPerim()
    {
        return 2 * 3.14159265 * radius;
    };
};

int main() {
    Rectangle rect(3, 4);
    Circle circle(5);

    std::cout << "Rectangle area: " << rect.getArea() << std::endl;
    std::cout << "Rectangle perimeter: " << rect.getPerim() << std::endl;
    std::cout << "Circle area: " << circle.getArea() << std::endl;
    std::cout << "Circle perimeter: " << circle.getPerim() << std::endl;

    return 0;
}
```

运行结果：

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter8> g++ 8-6.cpp

PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter8> ./a.exe
Rectangle area: 12
Rectangle perimeter: 14
Circle area: 78.5398
Circle perimeter: 31.4159
```

## 8-7

对类Point重载“++”（自增）、“--”（自减）运算符，要求同时重载前缀和后缀的形式。  

源码：

```cpp
#include <bits/stdc++.h>

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    Point& operator ++() {
        x++;
        y++;
        return *this;
    }

    Point& operator --() {

        x--;
        y--;
        return *this;
    }

    Point operator ++(int) {
        Point temp = *this;
        ++*this;
        return temp;
    }

    Point operator --(int) {
        Point temp = *this;
        --*this;
        return temp;
    }

    
    
};

int main() {
    Point p(1, 2);
    std::cout << (++p).x << " " << p.y << std::endl;
    std::cout << (p++).x << " " << p.y << std::endl;
    std::cout << (--p).x << " " << p.y << std::endl;
    std::cout << (p--).x << " " << p.y << std::endl;
}
```

运行结果：

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter8> g++ 8-7.cpp

PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter8> ./a.exe
2 3
2 4
2 3
2 2
```
