//

#include<iostream>

using namespace std;

int main(void){
    int a = 1;

    int result_1 = !a | a;
    int result_2 = ~a | a;
    int result_3 = a ^ a;
    int result_4 = a >> 2;

    cout << "(1)" << result_1 << endl;
    cout << "(2)" << result_2 << endl;
    cout << "(3)" << result_3 << endl;
    cout << "(4)" << result_4 << endl;

    return 0;
}