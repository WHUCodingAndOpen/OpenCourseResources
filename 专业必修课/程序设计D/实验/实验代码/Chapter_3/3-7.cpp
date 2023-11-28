#include<iostream>
using namespace std;
short int division(unsigned short int a,unsigned short int b){
    if(b == 0)
        return -1;
    else{
        short int ans = a / b;
        return ans;
    }
}
int main(){
    int a = 5, b = 4;
    cout << "Please enter a and b : ";
    //cin >> a >> b;
    cout << "5 4" << endl;
    cout << "a / b = " << division(a,b) << endl;
    return 0;
}