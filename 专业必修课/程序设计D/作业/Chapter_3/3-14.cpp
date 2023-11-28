#include<iostream>

using namespace std;

double legendre(int n,double x){
    if(n == 0)
        return 1.0;
    else if(n == 1)
        return x;
    else
        return ((2*n-1)*x*legendre(n-1,x)-(n-1)*legendre(n-2,x))/n;
}


int main(){
    int n;
    double x;
    cout << "Please enter n and x : ";
    cin >> n >> x;
    cout << "Answer is " << legendre(n,x) << endl;
    return 0;
}