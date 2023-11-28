#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int n = rand() % 100 + 1; // n range from 1 to 100.
    int number;

    cout << "Please guess what n is : ";

    cin >> number;

    do{
        if(number > n)
            cout << number << " is bigger than n." << endl
                << "Guess again : ";
        else
            cout << number << " is smaller than n." << endl
                << "Guess again : ";
        cin >> number;
    }while(number != n);
    
    cout << "You are right! n = " << n << endl;

    return 0;
}