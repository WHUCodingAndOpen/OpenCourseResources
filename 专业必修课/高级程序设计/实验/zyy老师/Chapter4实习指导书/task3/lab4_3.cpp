#include <iostream>
#include <string>
class MyData
{
public:
    int year;
    int month;
    int day;
    MyData() = default;
    MyData(int year, int month, int day) : year(year), month(month), day(day) {}
    friend std::ostream &operator<<(std::ostream &out, const MyData myData)
    {
        out << "{" << myData.year << ","
            << myData.month << "," << myData.day << "}";
        return out;
    }
};

class Person
{
private:
    int num;
    bool sex;
    MyData birthDay;
    std::string idCardNum;

public:
    Person() = default;
    Person(int, bool, MyData, std::string);
    ~Person();
    Person(const Person &);
    inline void setNum(int = 0);
    inline void setSex(bool = 0);
    inline void setBirthDay(MyData);
    inline void setIdCardNum(std::string);
    friend std::ostream &operator<<(std::ostream &, const Person &);
};

Person::~Person()
{
}
Person::Person(int num0, bool sex0,
               MyData birthDay0,
               std::string idCardNum0) : num(num0), sex(sex0), birthDay(birthDay0), idCardNum(idCardNum0) {}

Person::Person(const Person &p)
{
    this->num = p.num;
    this->sex = p.sex;
    this->birthDay = p.birthDay;
    this->idCardNum = p.idCardNum;
}

void Person::setNum(int num0) { this->num = num0; }

void Person::setSex(bool sex0) { this->sex = sex0; }

void Person::setBirthDay(MyData birthDay0)
{
    // std::cout <<birthday0<<std::endl;
    this->birthDay = birthDay0;
    // std::cout <<this->birthDay<<std::endl;
}

void Person::setIdCardNum(std::string idCardNum0) { this->idCardNum = idCardNum0; }

std::ostream &
operator<<(std::ostream &out, const Person &p)
{
    out << "{" << p.num << ","
        << (p.sex ? "男" : "女") << ","
        << p.birthDay << ","
        << p.idCardNum << "}";

    return out;
}


int main(){
    Person person1;
    person1.setNum(1);
    person1.setBirthDay({2002,2,2});
    // std::cout << MyData{2002,1,1}<<std::endl;
    person1.setIdCardNum("111111111111111111");
    std::cout << person1 <<std::endl;

    Person person2(person1);
    std::cout << person2 << std::endl;



}