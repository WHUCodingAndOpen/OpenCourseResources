#include <bits/stdc++.h>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

// 比较函数，用于按姓名排序
bool compareByName(const Student &a, const Student &b) {
    return a.name < b.name;
}

// 比较函数，用于按年龄排序
bool compareByAge(const Student &a, const Student &b) {
    if (a.age == b.age) {
        return a.name < b.name; // 年龄相同时按姓名排序
    }
    return a.age < b.age;
}

int main() {
    int n;
    cin >> n;
    vector<Student> students(n);

    // 读取学生信息
    for (int i = 0; i < n; ++i) {
        cin >> students[i].id >> students[i].name >> students[i].age;
    }

    // 按姓名排序
    sort(students.begin(), students.end(), compareByName);

    // 输出按姓名排序的结果
    for (const auto &student : students) {
        cout << setw(3) << student.id << setw(6) << student.name << setw(3) << student.age << endl;
    }
    cout << endl; // 空行

    // 按年龄排序
    sort(students.begin(), students.end(), compareByAge);

    // 输出按年龄排序的结果
    for (const auto &student : students) {
        cout << setw(3) << student.id << setw(6) << student.name << setw(3) << student.age << endl;
    }

    return 0;
}
