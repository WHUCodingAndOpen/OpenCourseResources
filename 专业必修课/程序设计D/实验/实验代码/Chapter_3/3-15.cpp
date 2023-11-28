#include<iostream>
using namespace std;
int getPower(int x, int y){
    if(y < 0)
        return 0;
    else if(y == 0)
        return 1;
    else if(y == 1)
        return x;
    else
        return x * getPower(x, y-1);
}
double getPower(double x, int y){
    if(y < 0)
        return 1.0 / getPower(x, -y);
    else if(y == 0)
        return 1;
    else if(y == 1)
        return x;
    else
        return x * getPower(x, y-1);
}
int main(){
    int a,m;
    double b;
    cout << "Please enter a b m : ";
    cin >> a >> b >> m;
    int ans1 = getPower(a, m);
    double ans2 = getPower(b, m);
    cout << "Answer is " << ans1 << " and " << ans2 << endl;
    return 0;
}