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
    return 0;
}