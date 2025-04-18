// 声明一个对people类对象数组按编号排序的函数，一个按编号查找people对象的函数。
// 在测试程序中使用前面实验得到的结果声明教师数组和学生数组，分别对教师数组和学生数组进行排序和查找。

#include <algorithm>
#include <iostream>
#include "Student.h"
#include <cstring>


int main() {
    // 声明教师数组和学生数组
    Teacher teachers[3] = {
        Teacher("Alice", "T002", "F", Date(1980, 5, 15), "123456789012345", "Professor", "Computer Science"),
        Teacher("Bob", "T001", "M", Date(1975, 8, 20), "987654321098765", "Associate Professor", "Mathematics"),
        Teacher("Charlie", "T003", "M", Date(1982, 12, 1), "192837465091234", "Lecturer", "Physics")
    };
    Student students[3] = {
        Student("Dave", "S002", "M", Date(2000, 4, 10), "210987654321098", "CS101"),
        Student("Eve", "S001", "F", Date(2001, 11, 30), "321098765432109", "CS102"),
        Student("Frank", "S003", "M", Date(1999, 1, 22), "432109876543210", "CS103")
    };

    // 对教师数组进行排序
    sortPeopleByNumber(teachers);
    // 对学生数组进行排序
    sortPeopleByNumber(students);

    // 查找特定编号的教师
    const char* teacherNumberToFind = "T001";
    Teacher* foundTeacher = findPeopleByNumber(teachers, teacherNumberToFind);
    if (foundTeacher) {
        std::cout << "Found teacher with number " << teacherNumberToFind << ":\n";
        foundTeacher->displayPeople();
    } else {
        std::cout << "Teacher with number " << teacherNumberToFind << " not found.\n";
    }

    // 查找特定编号的学生
    const char* studentNumberToFind = "S001";
    Student* foundStudent = findPeopleByNumber(students, studentNumberToFind);
    if (foundStudent) {
        std::cout << "Found student with number " << studentNumberToFind << ":\n";
        foundStudent->displayPeople();
    } else {
        std::cout << "Student with number " << studentNumberToFind << " not found.\n";
    }

    return 0;
}
