#include "bits/stdc++.h"

int main() {
    // 声明一个整型数组
    std::vector<int> numbers = {50, 40, 30, 20, 10};

    // 使用find()查找元素
    int target = 30;
    auto it = std::find(numbers.begin(), numbers.end(), target);

    if (it != numbers.end()) {
        std::cout << "元素 " << target << " 在数组中的位置是: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "元素 " << target << " 不在数组中" << std::endl;
    }

    // 使用sort()进行升序排序
    std::sort(numbers.begin(), numbers.end());

    // 输出排序后的数组
    std::cout << "升序排序后的数组: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用sort()和greater<T>()进行降序排序
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // 输出排序后的数组
    std::cout << "降序排序后的数组: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}