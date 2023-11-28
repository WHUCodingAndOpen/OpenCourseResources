#include <iostream>
#include <cmath>
const int SIZE = 3;
void transposeMatrix(int matrix[SIZE][SIZE]) {
    int temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            std::swap(matrix[i][j],matrix[j][i]);
        }
    }
}
void printMatrix(const int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    int matrix[SIZE][SIZE] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    /* 手动输入矩阵
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            std::cin >> matrix[i][j]; 
        }
    }
    */
    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);
    transposeMatrix(matrix);
    std::cout << "\nTransposed Matrix:" << std::endl;
    printMatrix(matrix);
    return 0;
}
