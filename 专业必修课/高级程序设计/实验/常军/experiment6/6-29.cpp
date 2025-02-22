#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3};
    double *p = reinterpret_cast<double *>(&arr[0]);
    *p = 5;
    cout << arr[0] <<" "<< arr[1] <<" "<< arr[2] << endl;
    return 0;
}