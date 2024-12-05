#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    if (isPrime(num)) {
        cout << num << " 是质数。" << endl;
    }else{
        cout << num << " 不是质数。" << endl;
    }
}