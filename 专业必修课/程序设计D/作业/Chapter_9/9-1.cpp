// 程序中提示输入班级中的学生人数 N，再依次提示用户输入N个人在课程A中的考试成绩，然后计算出平均成绩，显示出来。
// 请使用本章中的数组类模板Array定义浮点型数组存储考试成绩。
#include <iostream>
#include "Array.h"

int main() {
    int N;
    std::cout << "Enter the number of students: ";
    std::cin >> N;

    Array<float> scores(N);  // 使用Array类模板存储浮点型数组

    // 输入每个学生在课程A中的考试成绩
    for (int i = 0; i < N; ++i) {
        std::cout << "Enter score for student " << i + 1 << ": ";
        std::cin >> scores[i];
    }

    // 计算平均成绩
    float total = 0.0;
    for (int i = 0; i < N; ++i) {
        total += scores[i];
    }
    float average = total / N;

    // 显示平均成绩
    std::cout << "Average score: " << average << std::endl;

    return 0;
}
