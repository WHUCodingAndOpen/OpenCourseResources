# 第十二章作业

## 12-1

设计一个异常Exception 抽象类，在此基础上派生一个OutOfMemory类响应内存不足，一个RangeError类响应输入的数不在指定范围内，实现并测试这几个类。

源码：

```cpp
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
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter12]
└─$ g++ 12-1.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter12]
└─$ ./a.out
捕获到异常: 内存不足
捕获到异常: 输入的数不在指定范围内
```

## 12-2

在程序中用new 分配内存时，如果操作未成功，则用try 语句触发一个字符型异常，用catch 语句捕获此异常。

源码：

```cpp
#include <bits/stdc++.h>

int main()
{
    try
    {
        try
        {
            // 尝试分配一个非常大的内存块
            int *largeArray = new int[1000000000000000000ULL];

            delete[] largeArray;
        }
        catch (const std::bad_alloc &e)
        {
            // 捕获 std::bad_alloc 异常
            // 说实话我觉得这挺搞笑的
            char msg[] = "内存分配失败";
            throw msg;
        }
    }
    catch (const char *msg)
    {
        std::cerr << "自定义异常: " << msg << std::endl;
    }

    return 0;
}
```

运行结果

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter12]
└─$ g++ 12-2.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter12]
└─$ ./a.out
自定义异常: 内存分配失败
```

## 12-3

定义一个异常类CException，有成员函数Reason（），用来显示异常的类型，定义函数fn1（）触发异常，在主函数的try模块中调用fn1（），在catch模块中捕获异常，观察程序的执行流程。

源码：

```cpp
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
        std::cout << e.Reason() << std::endl;
    }
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter12]
└─$ g++ 12-3.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter12]
└─$ ./a.out
捕获异常: fn1()
fn1()
```
