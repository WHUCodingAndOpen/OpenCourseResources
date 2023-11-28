#include<bits/stdc++.h>

using namespace std;

void initialization(){
    cout << "Menu: A(dd) D(elete) S(ort) Q(uit),Select one: " << endl;
}

int main(void){
    initialization();
    char choice;

    while(cin >> choice){
        switch(choice){
            case 'A':
            case 'a':
                cout << "Data has been added." << endl;
                initialization();
                break;

            case 'D':
            case 'd':
                cout << "Data has been deleted." << endl;
                initialization();
                break;

            case 'S':
            case 's':
                cout << "Data has been sorted." << endl;
                initialization();
                break;
            
            case 'Q':
            case 'q':
                cout << "Program quitting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                initialization();
                break;
        }
    }
    return 0;
}