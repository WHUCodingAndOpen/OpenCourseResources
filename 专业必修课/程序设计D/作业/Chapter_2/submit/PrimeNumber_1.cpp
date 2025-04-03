#include <iostream>

using namespace std;


int main() {
    
    int num = 2;

    while (num <= 100) {
        int i = 2;
        bool PrimeNumber = true;

        while (i <= num / 2) {
            if (num % i == 0) {
                PrimeNumber = false;
                break;
            }
            i++;
        }

        if (PrimeNumber)
           cout << num << " ";

        num++;
    }

    return 0;
}
