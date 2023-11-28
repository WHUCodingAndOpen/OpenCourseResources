#include <iostream>
#include <cstring>

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
    People(const char *name = "", const char *number = "", const char *sex = "", const Date &birthday = Date(), const char *id = "") : birthday(birthday) {
        strcpy(this->name, name);
        strcpy(this->number, number);
        strcpy(this->sex, sex);
        strcpy(this->id, id);
    }

    // 复制函数
    People(const People &other) : birthday(other.birthday) {
        strcpy(this->name, other.name);
        strcpy(this->number, other.number);
        strcpy(this->sex, other.sex);
        strcpy(this->id, other.id);
    }
    
    // 展示人员信息
    void displayPeople() const;
    
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


// Student类
class Student : virtual public People {
public:
    Student(const char *name = "", const char *number = "", const char *sex = "", const Date &birthday = Date(), const char *id = "", const char *classNO = "")
        : People(name, number, sex, birthday, id) {
        strcpy(this->classNO, classNO);
    }
protected:
    char classNO[7];
};
// Teacher类
class Teacher : virtual public People {
public:
    Teacher(const char *name = "", const char *number = "", const char *sex = "", const Date &birthday = Date(), const char *id = "", const char *principalship = "", const char *department = "")
        : People(name, number, sex, birthday, id) {
        strcpy(this->principalship, principalship);
        strcpy(this->department, department);
    }
protected:
    char principalship[11], department[21];
};

// Graduate类
class Graduate : virtual public Student {
public:
    Graduate(const char *name = "", const char *number = "", const char *sex = "", const Date &birthday = Date(), const char *id = "", const char *classNO = "", const char *subject = "", const Teacher &adviser = Teacher())
        : People(name, number, sex, birthday, id), Student(name, number, sex, birthday, id, classNO), adviser(adviser) {
        strcpy(this->subject, subject);
    }
    void displayPeople() const {
        People::displayPeople();
        cout << "\nClass Number: " << classNO
             << "\nSubject: " << subject
             << "\nAdviser Information:\n";
        adviser.displayPeople();
    }

protected:
    char subject[21];
    Teacher adviser;
};

// TA类
class TA : public Graduate, public Teacher {
public:
    TA(const char *name = "", const char *number = "", const char *sex = "", const Date &birthday = Date(), const char *id = "", const char *classNO = "", const char *subject = "", const Teacher &adviser = Teacher(), const char *principalship = "", const char *department = "")
        : People(name, number, sex, birthday, id), Student(name, number, sex, birthday, id, classNO), Graduate(name, number, sex, birthday, id, classNO, subject, adviser), Teacher(name, number, sex, birthday, id, principalship, department) {}

    void displayPeople() const {
        Graduate::displayPeople();
        cout << "\nPrincipalship: " << principalship
             << "\nDepartment: " << department;
    }

};


int main() {
    cout << "Welcome to HR management!" << endl;

    // 创建一个学生对象
    Student student("Alice", "S001", "F", Date(1998, 5, 10), "123456789", "CS101");
    cout << "\nStudent Information:\n";
    student.displayPeople();

    // 创建一个教师对象
    Teacher teacher("Smith", "T001", "M", Date(1980, 8, 15), "987654321", "Professor", "Computer Department");
    cout << "\nTeacher Information:\n";
    teacher.displayPeople();

    // 创建一个研究生对象
    Teacher thesisAdviser("Prof. Johnson", "T002", "F", Date(1975, 3, 20), "654321987", "Associate Professor", "Physics Department");
    Graduate graduate("Bob", "G001", "M", Date(1995, 12, 3), "789012345", "PH101", "Physics", thesisAdviser);
    cout << "\nGraduate Information:\n";
    graduate.displayPeople();

    // 创建一个助教对象
    TA ta("Eve", "TA001", "F", Date(1997, 7, 25), "111222333", "CS201", "Computer Networks", thesisAdviser, "Lab Assistant", "Computer Department");
    cout << "\nTeaching Assistant Information:\n";
    ta.displayPeople();



    return 0;
}
