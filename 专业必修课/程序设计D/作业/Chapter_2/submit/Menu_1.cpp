#include <iostream>

using namespace std;

void initialization(){
    cout << "Menu: A(dd) D(elete) S(ort) Q(uit),Select one: ";
}


int main(){
    initialization();

    char choice;
    while(cin >> choice){

        if(choice == 'A' || choice == 'a'){
            cout << "Data has been added." << endl;
            initialization();
            continue;
        } 
        else if(choice == 'D' || choice == 'd'){
            cout << "Data has been deleted." << endl;
            initialization();
            continue;
        } 
        else if(choice == 'S' || choice == 's'){
            cout << "Data has been sorted." << endl;
            initialization();
            continue;
        } 
        else if(choice == 'Q' || choice == 'q'){
            cout << "Program quitting." << endl;
            break;
        }
        else{
            cout << "Invalid choice. Please try again." << endl;
            initialization();
            continue;
        }
    }
    return 0;
}