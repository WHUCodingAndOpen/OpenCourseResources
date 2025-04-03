// 并未找到实验10中的学生类数组 因此定义了一个Student类，其中包含学生的姓名、年龄和成绩
// 编写学生类数组,输入数据,显示出来,使用I/O流把此数组的内容写入磁盘文件,再显示出文件内容
#include <iostream>
#include <fstream>
#include <vector>

class Student {
public:
    std::string name;
    int age;
    double grade;

    Student() : name(""), age(0), grade(0.0) {}

    Student(const std::string& name, int age, double grade)
        : name(name), age(age), grade(grade) {}

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.name << " " << student.age << " " << student.grade;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Student& student) {
        is >> student.name >> student.age >> student.grade;
        return is;
    }
};

int main() {
    std::vector<Student> students;
    std::string filename = "students.txt";

    // 输入学生数据
    std::cout << "Enter student data (name age grade):" << std::endl;
    Student temp;
    while (std::cin >> temp) {
        students.push_back(temp);
        if (std::cin.peek() == '\n') break; // 假设一行输入表示结束
    }

    // 显示学生数据
    std::cout << "\nEntered student data:" << std::endl;
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }

    // 写入文件
    std::ofstream out_file(filename, std::ios::binary);
    if (!out_file) {
        std::cerr << "Cannot open file for writing." << std::endl;
        return 1;
    }
    for (const auto& student : students) {
        out_file << student << std::endl;
    }
    out_file.close();

    // 从文件读取并显示内容
    std::ifstream in_file(filename, std::ios::binary);
    if (!in_file) {
        std::cerr << "Cannot open file for reading." << std::endl;
        return 1;
    }
    std::cout << "\nContent from the file:" << std::endl;
    while (in_file >> temp) {
        std::cout << temp << std::endl;
    }
    in_file.close();

    return 0;
}
