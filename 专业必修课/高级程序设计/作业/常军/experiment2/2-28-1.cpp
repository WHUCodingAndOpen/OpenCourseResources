#include <iostream>

int main() {
    int num = 2; // 从2开始检查
    while (num <= 100) {
        bool isPrime = true;
        int divisor = 2;
        while (divisor * divisor <= num) {
            if (num % divisor == 0) {
                isPrime = false;
                break;
            }
            divisor++;
        }
        if (isPrime) {
            std::cout << num << " ";
        }
        num++;
    }
    return 0;
}