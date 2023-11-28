#ifndef CLIENT
#define CLIENT


#include<string>
using namespace std;
class Client{
public:
    Client() = default;
    Client(string ServerName, int ClientNum);
    ~Client() = default;
    
    string getServerName() const;
    int getClientNum() const;

    void ChangeServerName(string newName);
private:
    string ServerName;
    int ClientNum; 
};





#endif