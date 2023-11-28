#include <iostream>

using namespace std;


int main(){
    int num = 2;

    do{
        int i = 2;
        bool PrimeNumber = true;

        do{
            if(num % i == 0){
                PrimeNumber = false;
                break;
            }
            i++;
        } while (i <= num / 2);

        if(PrimeNumber)
            cout << num << " ";

        num++;
    }while (num <= 100);

    return 0;
}
