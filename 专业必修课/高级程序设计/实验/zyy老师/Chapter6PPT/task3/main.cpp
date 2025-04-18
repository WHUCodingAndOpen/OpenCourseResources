#include <iostream>
using namespace std;
void tryToModifyArray(const int[]); // function prototype
int main()
{
    int a[] = {10, 20, 30};
    tryToModifyArray(a);
    cout << a[0] << " " << a[1] << " " << a[2] << '\n';

    return 0;
} // end main

void tryToModifyArray(const int b[])
{
    // b[0] /= 2; // compilation error
    // b[1] /= 2; // compilation error
    // b[2] /= 2; // compilation error
} // end function tryToModi fyArray
