#include <iostream>
using namespace std;
void staticArrayInit(void);    // function prototype .
void automaticArrayInit(void); // function prototype
const int arraySize = 3;
int main()
{
    cout << "First call to each function:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << "\n\nSecond cal1 to each function:\n";
    staticArrayInit();
    automaticArrayInit();
    cout << endl;
} // end main

// function to demonstrate a static 1ocal array
void staticArrayInit(void)
{
    // initializes elements to 0 first time function is called
    static int array1[arraySize]; // static 1oca1 array 执行值初始化，数组成员都为0
    cout << "\nValues on entering staticArrayInit:\n";
    // output contents of array1
    for (int i = 0; i < arraySize; i++)
        cout << "array1[" << i << "] = " << array1[i] << "  "; // (1)0 0 0 (2)5 5 5

    cout << "\nValues on exiting staticArrayInit:\n";
    // modify and output contents of array1
    for (int j = 0; j < arraySize; j++)
        cout << "array1[" << j << "] = " << (array1[j] += 5) << "  "; // (1)5 5 5 (2)10 10 10
} // end function stati CArrayInit

// function to demonstrate an automatic 1oca1 array
void automaticArrayInit(void)
{
    // initializes elements each time function is called
    int array2[arraySize] = {1, 2, 3}; // automatic 1oca1 array
    cout << "\n\nValues on entering automaticArrayInit:\n";
    // output contents of array2
    for (int i = 0; i < arraySize; i++)
        cout << "array2[" << i << "] = " << array2[i] << "  "; // (1)1 2 3 (2)1 2 3

    cout << "\nValues on exiting automaticArrayInit:\n";
    // modify and output contents of array2
    for (int j = 0; j < arraySize; j++)
        cout << "array2[" << j << "] = " << (array2[j] += 5) << "  "; // (1)6 7 8 (2)6 7 8
} // end function automati CArrayInit
