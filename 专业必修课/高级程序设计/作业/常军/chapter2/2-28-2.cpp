#include <iostream>

int main() {
    int num = 2; // 从2开始检查
    std::cout << num << " ";
    do {
        bool isPrime = true;
        int divisor = 2;
        do {
            if (num % divisor == 0) {
                isPrime = false;
                break;
            }
            divisor++;
        } while (divisor * divisor <= num);
        if (isPrime) {
            std::cout << num << " ";
        }
        num++;
    } while (num <= 100);
    return 0;
}