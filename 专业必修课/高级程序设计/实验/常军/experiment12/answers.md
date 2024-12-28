# 第十二章实验

## 12-1

编写程序12-1.cpp，在Cexception类的成员函数Reason()中用cout显示异常的类型，在函数fn1()中通throw语句触发异常，在主函数的try模块中调用fn1()，在catch模块中捕获异常。

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
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment12]
└─$ g++ 12-1.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment12]
└─$ ./a.out
捕获异常: fn1()
fn1()
```
