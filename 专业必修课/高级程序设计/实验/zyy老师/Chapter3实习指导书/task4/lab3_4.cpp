#include <iostream>
#include <cassert>
using UINT64 = unsigned long long;

#define MYPRINT(n) \
    std::cout << #n << " = " << n << std::endl

inline constexpr UINT64
fib(const unsigned int &n)
{
    assert(n > 0);
    return 1 == n || 2 == n ? 1 : fib(n - 1) + fib(n - 2);
}

UINT64
detailedFib(const unsigned int &n)
{

    if (1 == n || 2 == n)
    {
        std::cout << "arrived exit and return 1" << std::endl;
        return 1;
    }
    if (n > 2)
    {
        std::cout << "call detailedFib(" << n - 1
                  << ") and detailedFib(" << n - 2
                  << ")" << std::endl;
        return detailedFib(n - 1) + detailedFib(n - 2);
    }

    return 0;
}

int main()
{

    MYPRINT(fib(5));

    MYPRINT(detailedFib(5));

    return 0;
}