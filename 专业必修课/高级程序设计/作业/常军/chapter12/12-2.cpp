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