#include<iostream>
using namespace std;
double conversion(double f) {
    double c;
    c = (f - 32) * 5 / 9;
    return c;
}
int main() {
    cout << "Please enter 'F : ";
    double f = 35.0;
    cout <<  "35.0" << endl;
    cout << "'C is " << conversion(f) << endl;
    return 0;
}