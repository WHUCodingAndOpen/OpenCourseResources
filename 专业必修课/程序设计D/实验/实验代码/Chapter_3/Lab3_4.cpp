#include<iostream>
using namespace std;
int Fibonacci(int n){
    if(n <= 1)
        return 1;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}
int main(){
    int n;
    cout << "Please enter n: ";
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << Fibonacci(i) << endl;
    }
    return 0;
}