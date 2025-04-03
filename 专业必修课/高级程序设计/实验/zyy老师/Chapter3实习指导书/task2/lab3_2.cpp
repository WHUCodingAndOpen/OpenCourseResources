#include <iostream>

#define MYPRINT(n) \
    std::cout << #n << " = " << n << std::endl

inline constexpr int
Max1(const int &val1, const int &val2)
{
    return val1 > val2 ? val1 : val2;
}

inline constexpr int
Max1(const int &val1, const int &val2, const int &val3)
{
    return Max1(val1, val2) > val3 ? Max1(val1, val2) : val3;
}

inline constexpr double
Max1(const double &val1, const double &val2)
{
    return val1 > val2 ? val1 : val2;
}

inline constexpr double
Max1(const double &val1, const double &val2, const double &val3)
{
    return Max1(val1, val2) > val3 ? Max1(val1, val2) : val3;
}

int main()
{

    MYPRINT(Max1(1, 2));
    MYPRINT(Max1(84, 44, 25));

    MYPRINT(Max1(1.99, 9.8));
    MYPRINT(Max1(5.9, 6.7, 2.3));

    return 0;
}