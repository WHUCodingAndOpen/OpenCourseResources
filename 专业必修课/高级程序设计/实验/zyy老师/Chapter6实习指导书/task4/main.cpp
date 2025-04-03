#include <iostream>
#include <string>
using namespace std;



int main(){

    string s1 = "Hello,";
    string s2 = "World!!!";

    string out = s1.append(s2);
    cout << out <<endl;

    return 0;
}