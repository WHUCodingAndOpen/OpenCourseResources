#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
    void display() {
        cout << year << "-" << month << "-" << day << endl;
    }
};

class Person {
    
private:
    int id;
    string gender;
    Date birthDate;
    string idCard;
public:
    Person(int i, string g, Date b, string ic="12345") : id(i), gender(g), birthDate(b), idCard(ic) {}
    Person(const Person& p) : id(p.id), gender(p.gender), birthDate(p.birthDate), idCard(p.idCard) {}
    void display() {
        cout << "编号：" << id << endl;
        cout << "性别：" << gender << endl;
        cout << "出生日期：";
        birthDate.display();
    }

    ~Person() {
        cout << "析构函数被调用" << endl;
    }
};

int main() {
    Date d(2000, 1, 1);
    Person p(1, "男", d);
    Person p2(p);
    p.display();
    p2.display();
    return 0;
}