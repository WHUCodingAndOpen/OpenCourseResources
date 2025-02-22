#include <bits/stdc++.h>

class Shape
{
public:
    virtual double getArea() = 0;
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
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea()
    {
        return 3.14159 * radius * radius;
    }
};

class Square : public Rectangle
{
public:
    Square(double s) : Rectangle(s,s) {};
    double getArea()
    {
        return length * width;
    };
};

int main() {
    Rectangle rect(3, 4);
    Circle circle(5);
    Square square(2);

    std::cout << "Rectangle area: " << rect.getArea() << std::endl;
    std::cout << "Circle area: " << circle.getArea() << std::endl;
    std::cout << "Square area: " << square.getArea() << std::endl;

    return 0;
}