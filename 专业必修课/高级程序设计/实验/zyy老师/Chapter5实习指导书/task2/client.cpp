#include "client.h"

std::string Client::serverName = "server";
int Client::clientNum = 1;

void Client::changeServerName(std::string s){
    Client::serverName = s;
}