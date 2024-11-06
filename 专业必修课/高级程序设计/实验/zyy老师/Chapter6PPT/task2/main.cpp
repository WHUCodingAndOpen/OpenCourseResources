#include <iostream>
#include <iomanip> // io manipulator
// 主要是对cin、cout之类的一些操纵运算子，类似c语言的格式化输出
using namespace std;

void modifyArray(int[], int); // appears strange; array and size
void modifyElement(int);      // receive array e1 ement value
int main()
{
    const int arraySize = 5;            // size of array a
    int a[arraySize] = {0, 1, 2, 3, 4}; // initialize array a
    cout << "Effects of passing entire array by reference:"
         << "\n\nThe values of the origina1 array are:\n";
    // output original array elements
    for (int i = 0; i < arraySize; i++)
        cout << setw(3) << a[i]; // 保证宽度为3，但是宽度大于3时（如1000），该函数不起作用

    cout << endl;
    // pass array a to modifyArray by reference
    modifyArray(a, arraySize);
    cout << "The values of the modified array are:\n";
    // output modified array e1 ements
    for (int j = 0; j < arraySize; j++)
        cout << setw(3) << a[j];
    cout << "\n\n\nEffects of passing array element by value:"
         << "\n\na[3] before modifyElement:"
         << a[3] << endl;
    modifyElement(a[3]); // pass array element a[ 3] by value
    cout << "a[3] after modifyElement: " << a[3] << endl;
    return 0;
} // end main

// in function modi fyArray, "b"points to the origina array "a" in memory
void modifyArray(int b[], int sizeOfArray)
{
    for (int k = 0; k < sizeOfArray; k++)
    {
        b[k] *= 2;
    }
}
// in function modi fyE1 ement, "e" is a 1oca1 copy of
// array element a[ 3 ] passed from main
void modifyElement(int e)
{
    // multiply parameter by 2
    cout << "Value of element in modifyElement:"
         << (e *= 2) << endl;
} // end function modi fyE1 ement
