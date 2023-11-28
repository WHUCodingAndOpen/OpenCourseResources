// 对people类重载"=="运算符和"="运算符
// "=="运算符判断两个 people 类对象的id属性的大小 "="运算符实现people类对象的赋值操作


#include <iostream>
#include <cstring>

using namespace std;

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

    bool operator==(const People &other) const {
        return strcmp(this->id, other.id) == 0;
    }

    // 重载"="运算符
    People& operator=(const People &other) {
        if (this != &other) { // 防止自赋值
            strcpy(this->name, other.name);
            strcpy(this->number, other.number);
            strcpy(this->sex, other.sex);
            strcpy(this->id, other.id);
            this->birthday = other.birthday;
        }
        return *this;
    }
private:
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

void People::updatePeopleInfo(const char *newName, const char *newNumber, const char *newSex, const Date &newBirthday, const char *newId) {
    strcpy(name, newName);
    strcpy(number, newNumber);
    strcpy(sex, newSex);
    strcpy(id, newId);
    birthday = newBirthday;
} 

int main() {
    cout << "Welcome to HR management!" << endl;

    const int numPeople = 3;
    People peopleArray[numPeople] = {
        People("John", "001", "M", Date(1990, 1, 1), "123456789"),
        People("Jane", "002", "F", Date(1995, 2, 2), "987654321"),
        People("Jake", "003", "M", Date(2006, 2, 22), "456789012")
    };

    for (int i = 0; i < numPeople; i++) {
        cout << "\nPerson " << i + 1 << ":\n";
        peopleArray[i].displayPeople();
    }

    // 测试重载的"=="运算符
    if (peopleArray[0] == peopleArray[1]) {
        cout << "Person 1 and Person 2 have the same ID." << endl;
    } else {
        cout << "Person 1 and Person 2 have different IDs." << endl;
    }

    // 测试重载的"="运算符
    People newPerson;
    newPerson = peopleArray[0]; // 使用重载的"="运算符进行赋值
    cout << "\nNew Person:\n";
    newPerson.displayPeople();



    return 0;
}