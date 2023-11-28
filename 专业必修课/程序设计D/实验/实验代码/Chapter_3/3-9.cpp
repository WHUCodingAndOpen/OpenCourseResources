#include<iostream>

using namespace std;

bool isPrime(int num);

int main() {
    int number = 55;
    cout << "请输入一个整数: 55" << endl;
    //cin >> number;
    if (isPrime(number)) {
        cout << number << " 是质数" << endl;
    } else {
        cout << number << " 不是质数" << endl;
    }
    return 0;
}

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
