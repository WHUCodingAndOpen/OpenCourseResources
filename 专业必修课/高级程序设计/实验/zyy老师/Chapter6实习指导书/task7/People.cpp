#include <iostream>
#include <array>
#include <cstring>
#define MYPRINT(n) \
    std::cout << #n << " = " << n << std::endl
class MyDate
{
public:
    int year;
    int month;
    int day;
    MyDate() = default;
    MyDate(int year, int month, int day) : year(year), month(month), day(day) {}
    friend std::ostream &operator<<(std::ostream &out, const MyDate myDate)
    {
        out << "{" << myDate.year << ","
            << myDate.month << "," << myDate.day << "}";
        return out;
    }
};

class People
{
private:
    char name[11]{};
    char number[7]{};
    char sex[3];
    MyDate birthday{};
    char id[16]{};
public:
    People() = default;
    ~People() = default;
    People(People&) = default;

    inline void setName(const char name0[]){
        memmove(name,name0,11);
    }
    inline void setNumber(const char number0[]){
        memmove(number,number0,7);
    }
    inline void setSex(const char sex0[]){
        memmove(sex,sex0,3);
    }
    inline void setBirthday(const MyDate& date){
        memmove(&birthday,&date,sizeof(MyDate));
    }
    inline void setId(const char id0[]){
        memmove(id,id0,16);
    }
    inline void disPlay(){
        MYPRINT(name);
        MYPRINT(number);
        MYPRINT(sex);
        MYPRINT(birthday);
        MYPRINT(id);
    }

};



int main(){

    std::array<People,5> peopleArray{};
    for (auto &e:peopleArray){
        e.setName("jack");
        e.setId("123456789098765");
        e.setNumber("123456");
        e.setSex("xy");
        e.setBirthday(MyDate{2002,2,2});
        e.disPlay();
    }

    for (auto &e:peopleArray){
        e.disPlay();
    }
    

    return 0;
}
