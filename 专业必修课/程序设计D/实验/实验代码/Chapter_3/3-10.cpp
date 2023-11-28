#include<iostream>

using namespace std;

int findGCD(int a, int b);
int findLCM(int a, int b);

int main() {

    int num1 = 1024, num2 = 2526;
    cout << "请输入第一个整数: 1024" << endl;
    //cin >> num1;
    cout << "请输入第二个整数: 2526" << endl;
    //cin >> num2;
    cout << "最大公约数是: " << findGCD(num1, num2) << endl;
    cout << "最小公倍数是: " << findLCM(num1, num2) << endl;
    return 0;
}
int findGCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return findGCD(b, a % b);
}
int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}
