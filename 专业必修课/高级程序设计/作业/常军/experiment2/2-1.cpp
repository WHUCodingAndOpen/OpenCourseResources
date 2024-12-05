#include <iostream>
using namespace std;
int main()
{
    int radius;
    cout << "Please enter the radius!\n";
    
    cin >> radius;

    cout << "The radius is: " << radius << '\n';
    cout << "PI is: " << 3.14 << '\n';
    cout << "Please enter a different radius!\n";
    cin >> radius;
    cout << "Now the radius is changed to: " << radius << '\n';
    return 0;
}
// 观察：通过调试功能跟踪观察变量的值
