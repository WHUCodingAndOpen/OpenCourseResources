#include <iostream>

inline constexpr double
temperF2C(const double &F)
{
    return (F - 32) * 5.0 / 9.0;
}

int main()
{

    std::cout << temperF2C(66.0);
    return 0;
}