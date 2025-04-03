// 简单说明插入排序的算法思想。
// 初始化数组 data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
// 用教材中的直接插入排序函教模板进行排序。
// 对此函教模板捕作修改，加入输出语句，在每输入一个待排序元素后显示整个教组，观测排序过程中教据的变化，加深对插入排序算法的理解

// 插入排序的算法思想是将一个数据序列分为两个部分，前面的部分是已经排序好的，后面的部分是未排序的。
// 在排序过程中，逐个将未排序部分的元素插入到已排序部分的适当位置，直到所有元素都排序完毕。
    #include <iostream>
    #include <algorithm>
    #include <cmath>
    #include <iostream>

    template<typename T, size_t N>
    void insertionSort(T (&data)[N]) {
        for (size_t i = 1; i < N; ++i) {
            T key = data[i];
            size_t j = i;
            while (j > 0 && data[j - 1] > key) {
                data[j] = data[j - 1];
                --j;
            }
            data[j] = key;

            std::cout << "After inserting element " << key << ": ";
            for (size_t k = 0; k < N; ++k) {
                std::cout << data[k] << " ";
            }
            std::cout << std::endl;
        }
    }

    int main() {
        int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        insertionSort(data);

        std::cout << "Sorted array: ";
        for (int n : data) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        return 0;
    }
