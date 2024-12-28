#include <bits/stdc++.h>

class CException
{
public:
    CException(const char *reason)
    {
        this->reason = reason;
    }
    const char *Reason()
    {
        std::cout << reason << std::endl;
        return reason;
    }

private:
    const char *reason;
};

void fn1()
{
    throw CException("fn1()");
}

int main(){
    try
    {
        fn1();
    }
    catch (CException &e)
    {
        std::cout << "捕获异常: " << e.Reason() << std::endl;
    }
}