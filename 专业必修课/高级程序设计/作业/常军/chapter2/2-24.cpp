#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    cout << (!a|a) << endl ;
    cout << (~a|a) << endl ;
    cout << (a^a) << endl ;
    cout << (a>>2) << endl ;
}