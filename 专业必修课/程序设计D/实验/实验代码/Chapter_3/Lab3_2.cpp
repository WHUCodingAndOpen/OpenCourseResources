#include<iostream>
#include<cmath>
using namespace std;
int max1(int a,int b){
    if(a >= b)   return a;
    else return b;
}
int max1(int a,int b,int c){
    int max_num;
    if(a >= b)  max_num = a;
    else max_num = b;
    if(max_num < c) max_num = c;
    return max_num;
}
double max1(double a,double b){
    if(a >= b)   return a;
    else return b;
}
double max1(double a,double b,double c){
    double max_num;
    if(a >= b)  max_num = a;
    else max_num = b;
    if(max_num < c) max_num = c;
    return max_num;
}
int main(){
    int a1=1,b1=2,c1=3;
    double a2=1.2,b2=3.2,c2=9.9;
    cout << max1(a1,b1) << endl 
        << max1(a1,b1,c1) << endl
        << max1(a2,b2) << endl
        << max1(a2,b2,c2) << endl;
    return 0;
}