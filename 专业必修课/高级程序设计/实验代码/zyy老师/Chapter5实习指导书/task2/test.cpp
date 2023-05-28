#include "client.h"
#define MYPRINT(n) \
std::cout << #n << " = " << n << std::endl

int main(){

    MYPRINT(Client::serverName);

    MYPRINT(Client::clientNum);
    Client::changeServerName("newServerName");
    MYPRINT(Client::serverName);


    return 0;
}