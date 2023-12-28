
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>   
#include "LinkedList.h"
#include "Course.h"
using namespace std;
// Date类
class Date {
public:
    // 构造函数
    Date(int year = 2000, int month = 1, int day = 1) : year(year), month(month), day(day) {}
    
    // 析构函数
    ~Date() = default;

    // 展示时间信息
    void displayDate() const {
        cout << year << "-" << month << "-" << day;
    }
private:
    int year, month, day;
};

// People类
class People {
public:
    // 构造函数
    // 构造函数
    People(const char *name = "", const char *number = "", const char *sex = "", const Date &birthday = Date(), const char *id = "") : birthday(birthday) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        strncpy(this->number, number, sizeof(this->number) - 1);
        this->number[sizeof(this->number) - 1] = '\0'; 
        strncpy(this->sex, sex, sizeof(this->sex) - 1);
        this->sex[sizeof(this->sex) - 1] = '\0'; 
        strncpy(this->id, id, sizeof(this->id) - 1);
        this->id[sizeof(this->id) - 1] = '\0'; 
    }

    // 复制函数
    People(const People &other) : birthday(other.birthday) {
        strcpy(this->name, other.name);
        strcpy(this->number, other.number);
        strcpy(this->sex, other.sex);
        strcpy(this->id, other.id);
    }

    virtual ~People() {}
    
    // 展示人员信息
    void displayPeople() const;

    const char* getName() const {
        return name;
    }
    
    const char* getNumber() const {
        return number;
    }

    // 更新人员信息
    void updatePeopleInfo(const char *newName, const char *newNumber, const char *newSex, const Date &newBirthday, const char *newId);
protected:
    // name 姓名 | number 编号 | sex 性别 | id 身份证号
    char name[11], number[7], sex[3], id[16];
    // birthday Date类 出生日期
    Date birthday;
};

//内联成员函数
inline void People::displayPeople() const {
    cout << "Name: " << name << "\nNumber: " << number << "\nSex: " << sex << "\nBirth Date: ";
    birthday.displayDate();
    cout << "\nID : " << id << endl;
}

// 更新人员信息
void People::updatePeopleInfo(const char *newName, const char *newNumber, const char *newSex, const Date &newBirthday, const char *newId) {
    strcpy(name, newName);
    strcpy(number, newNumber);
    strcpy(sex, newSex);
    strcpy(id, newId);
    birthday = newBirthday;
}

class Student : public People {
public:
    Student(const char *name = "", const char *number = "", const char *sex = "", const Date &birthday = Date(), const char *id = "", const char *classNO = "")
        : People(name, number, sex, birthday, id) {
        strncpy(this->classNO, classNO, sizeof(this->classNO) - 1);
        this->classNO[sizeof(this->classNO) - 1] = '\0';
    }

    // 添加课程
    void addCourse(const Course &course) {
        courses.insertRear(course);
    }

    // 显示学生所修课程
    void displayCourses() const {
        if (courses.isEmpty()) {
            std::cout << "No courses taken." << std::endl;
            return;
        }

        Node<Course>* current = courses.getFront();
        while (current != nullptr) {
            current->data.displayCourse();
            current = current->nextNode();
        }
    }

    // 获取课程链表的头节点，用于外部遍历
    Node<Course>* getCourses() const {
        return courses.getFront();
    }

protected:
    char classNO[7]; // 班级编号
    LinkedList<Course> courses; // 存储课程的链表
};

// Teacher类
class Teacher : public People {
public:
    Teacher(const char *name = "", 
            const char *number = "", 
            const char *sex = "", 
            const Date &birthday = Date(), 
            const char *id = "", 
            const char *principalship = "", 
            const char *department = "")
        : People(name, number, sex, birthday, id) {
        strcpy(this->principalship, principalship);
        strcpy(this->department, department);
    }
protected:
    char principalship[11], department[21];
};

// 按编号排序People对象数组的函数
template <typename T, size_t N>
void sortPeopleByNumber(T (&peopleArray)[N]) {
    std::sort(peopleArray, peopleArray + N, [](const T& a, const T& b) {
        return std::strcmp(a.getNumber(), b.getNumber()) < 0;
    });
}

// 按编号查找People对象的函数
template <typename T, size_t N>
T* findPeopleByNumber(T (&peopleArray)[N], const char* number) {
    auto it = std::find_if(peopleArray, peopleArray + N, [number](const T& person) {
        return std::strcmp(person.getNumber(), number) == 0;
    });
    return (it != peopleArray + N) ? &(*it) : nullptr;
}

#endif