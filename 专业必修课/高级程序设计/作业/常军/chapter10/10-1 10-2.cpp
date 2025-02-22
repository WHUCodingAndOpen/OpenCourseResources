#include <iostream>
using namespace std;

template<typename T>
void insertionSort(T data[], int n) {
    for (int i = 1; i < n; ++i) {
        T key = data[i];
        int j = i - 1;

        // 将data[i]插入到已排序的data[0...i-1]中
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;

        // 输出当前数组状态
        cout << "After inserting element " << key << ": ";
        for (int k = 0; k < n; ++k) {
            cout << data[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(data) / sizeof(data[0]);

    insertionSort(data, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}