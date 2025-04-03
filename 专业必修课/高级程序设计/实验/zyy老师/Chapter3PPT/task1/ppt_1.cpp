#include <iostream>

using UINT64 = unsigned long long;

constexpr UINT64 factorial(const unsigned int n)
{
    return 0 == n || 1 == n ? 1 : n * factorial(n - 1);
}

int main()
{

    std::cout << factorial(5) << std::endl;

    return 0;
}