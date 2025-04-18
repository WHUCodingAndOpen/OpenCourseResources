// 简单说明选择排序的算法思想。
// 初始化数组 data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
// 用教材中的直接选择排序函教模板进行排序。
// 对此函教模板捕作修改，加入输出语句，在每输入一个待排序元素后显示整个教组，观测排序过程中教据的变化，加深对选择排序算法的理解

// 选择排序的算法思想是从待排序的数据序列中找出最小（或最大）的元素，存放在序列的起始位置，然后再从剩余未排序的元素中继续寻找最小（或最大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素都排序完毕

#include <iostream>

template<typename T, size_t N>
void selectionSort(T (&data)[N]) {
    for (size_t i = 0; i < N - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < N; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(data[i], data[minIndex]);
        }

        // 输出当前数组的状态
        std::cout << "After selecting element " << data[i] << ": ";
        for (size_t k = 0; k < N; ++k) {
            std::cout << data[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    selectionSort(data);

    std::cout << "Sorted array: ";
    for (int n : data) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
