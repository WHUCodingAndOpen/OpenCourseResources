#include <iostream>
using namespace std;
int main()
{
    const double pi(3.14159);
    int radius(0);
    cout << "The initial radius is:" << radius << '\n';
    cout << "PI is:" << pi << '\n';
    cout << "Please enter a different radius!\n";
    cin >> radius;
    cout << "Now the radius is changed to:" << radius << '\n';
    cout << "PI is still :" << pi << endl;
    return 0;
}
// 观察：通过调试工具跟踪观察变量