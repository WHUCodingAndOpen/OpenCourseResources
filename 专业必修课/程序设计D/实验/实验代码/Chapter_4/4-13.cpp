#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592635897;

class Circle{
public:
    Circle() = default;
    Circle(double r);
    Circle(Circle &r) = default;
    double getArea() const {return PI * pow(radius,2);}
    ~Circle() = default;
private:
    double radius;
};

Circle::Circle(double r) : radius(r) {}

int main(){
    cout << "Please enter the radius of the circle: ";
    int r;
    cin >> r;
    
    Circle round(r);

    cout << "The area of the circle is " << round.getArea() << endl;

    return 0;
}