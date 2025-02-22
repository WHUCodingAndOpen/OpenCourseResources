#include <iostream>
#include <cmath>
using namespace std;

int getPower(int x, int y){
    return pow(x,y);
}

double getPower(double x,int y){
    return pow(x,y);
}


int main(){
    int a,m;
    double b;
    cout << "请依次输入a,b,m: ";
    cin >> a >> b >> m;
    cout << getPower(a,m) << endl;
    cout << getPower(b,m) << endl;
    return 0;
}