#include <iostream>
#include <string>

// main.cpp
#include <iostream>
#include "Student.h"

int main() {
    // 创建一个学生对象
    Student student("John Doe", "123456", "M", Date(1995, 5, 15), "123456789012345", "CS101");

    // 添加课程
    student.addCourse(Course("Mathematics", 85));
    student.addCourse(Course("Physics", 90));
    student.addCourse(Course("Chemistry", 78));

    // 显示学生信息
    student.displayPeople();

    // 显示学生所修课程
    cout << "Courses taken:" << endl;
    student.displayCourses();

    return 0;
}
