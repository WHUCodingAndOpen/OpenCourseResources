#include <iostream>


class Client
{
public:
    static std::string serverName;
    static int clientNum;
public:
    static void changeServerName(std::string);
};
