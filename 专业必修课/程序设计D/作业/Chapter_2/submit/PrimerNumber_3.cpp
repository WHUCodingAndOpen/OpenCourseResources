#include <iostream>

using namespace std;

int main(){

    for(int num = 2;num <= 100;num++){
        bool PrimeNumber = true;

        for(int i = 2;i <= num / 2;i++){
            if (num % i == 0) {
                PrimeNumber = false;
            }
        }
    if (PrimeNumber)
           cout << num << " ";
    }
    return 0;
}