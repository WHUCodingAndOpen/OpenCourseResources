#include <iostream>
#include <string>
#include "client.h"

using namespace std;

int main(){
    string newName;
    Client client("WHUMC",1024);

    cout << "Now the server name is " << client.getServerName() << endl;
    cout << "Please enter a new name :";
    cin >> newName;
    client.ChangeServerName(newName);
    
    cout << "Now the new name is " << client.getServerName() << endl;

    return 0;
}