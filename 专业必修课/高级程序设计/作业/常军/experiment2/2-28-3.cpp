#include <iostream>

int main() {
    for (int num = 2; num <= 100; num++) {
        bool isPrime = true;
        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            std::cout << num << " ";
        }
    }
    return 0;
}