#include<iostream>

using namespace std;

int main(void){
    int a = 1,b = 2,c = 3;
    
    int result_1 = a | b - c;
    int result_2 = a ^ b & -c;
    int result_3 = a & b | c;
    int result_4 = a | b & c;

    cout << "(1)" << result_1 << endl;
    cout << "(2)" << result_2 << endl;
    cout << "(3)" << result_3 << endl;
    cout << "(4)" << result_4 << endl;


    return 0;
}