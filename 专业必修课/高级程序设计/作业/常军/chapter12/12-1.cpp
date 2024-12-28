#include <bits/stdc++.h>

class Exception
{
public:
    virtual ~Exception() {}
    virtual const char *what() const = 0; // 纯虚函数
};

class OutOfMemory : public Exception
{
public:
    const char *what() const override
    {
        return "内存不足";
    }
};

class RangeError : public Exception
{
public:
    const char *what() const override
    {
        return "输入的数不在指定范围内";
    }
};

void testOutOfMemory()
{
    try
    {
        throw OutOfMemory();
    }
    catch (const Exception &e)
    {
        std::cerr << "捕获到异常: " << e.what() << std::endl;
    }
}

void testRangeError()
{
    try
    {
        throw RangeError();
    }
    catch (const Exception &e)
    {
        std::cerr << "捕获到异常: " << e.what() << std::endl;
    }
}

int main()
{
    testOutOfMemory();
    testRangeError();
    return 0;
}