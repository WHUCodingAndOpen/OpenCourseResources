#include <iostream>

template <typename T>
void swap(T &v1, T &v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

int main()
{
    int a = 1;
    int b = 2;

    std::cout << "before swap : a = "
              << a
              << ", b = "
              << b
              << std::endl;
    swap(a, b);

    std::cout << "after swap : a = "
              << a
              << ", b = "
              << b
              << std::endl;

    return 0;
}