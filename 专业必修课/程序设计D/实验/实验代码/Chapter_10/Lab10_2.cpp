// 声明一个整型数组,使用C++标准模板库(STL)中的查找算法find()进行数据的查找
// 然后应用排序算法Sort(),并配合使用标准函数对象Greater<T>>对数据进行升序和降序排序
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6}; // 声明一个整型数组

    // 使用find查找元素5
    auto it = std::find(data.begin(), data.end(), 5);
    if (it != data.end()) {
        std::cout << "找到元素: " << *it << std::endl;
    } else {
        std::cout << "未找到元素" << std::endl;
    }

    // 使用sort和greater进行降序排序
    std::sort(data.begin(), data.end(), std::greater<int>());
    std::cout << "降序排序: ";
    for (int elem : data) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 使用sort进行升序排序
    std::sort(data.begin(), data.end());
    std::cout << "升序排序: ";
    for (int elem : data) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

