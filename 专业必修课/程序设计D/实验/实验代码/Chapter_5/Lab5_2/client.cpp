#include <iostream>
#include <string>
#include "client.h"

using namespace std;


Client::Client(string ServerName, int ClientNum) : ServerName(ServerName), ClientNum(ClientNum) {
    cout << "Constructor function has played a role." << endl;
}

string Client::getServerName() const { return ServerName; }
int Client::getClientNum() const { return ClientNum;}

void Client::ChangeServerName(string newName) {
    ServerName = newName;
}