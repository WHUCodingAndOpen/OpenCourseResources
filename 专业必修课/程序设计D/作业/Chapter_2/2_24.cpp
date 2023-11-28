#include<iostream>

using namespace std;

int main(void){
    cout << "Is it raining now?" << endl;
    cout << "Please enter Y/N." << endl;
    char word;
    cin >> word;
    if(word=='Y'||word=='y')
        cout << "It's raining now." << endl;
    else if(word=='N'||word=='n')
        cout << "It's not raining now." << endl;
    else 
    cout << "Is it raining now?" << endl;

    return 0;
}