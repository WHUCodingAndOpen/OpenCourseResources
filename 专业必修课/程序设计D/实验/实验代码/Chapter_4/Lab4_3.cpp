#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
    Date(int year = 2000, int month = 1, int day = 1)
        : year(year), month(month), day(day) {} // constructor
    void displayDate() const
    {
        cout << year << "-" << month << "-" << day;
    }
    ~Date() = default; // destructor
private:
    int year, month, day;
};

class People
{
public:
    People() = default; // default constructor
    People(int id, char gender, const Date &birthDate, const string &idNumber)
        : id(id), gender(gender), birthDate(birthDate), idNumber(idNumber) {} // constructor
    People(const People &other)
        : id(other.id), gender(other.gender), birthDate(other.birthDate), idNumber(other.idNumber) {} // copy constructor
    void displayPeople() const;
    void updatePeopleInfo(int newId = 0, char newGender = ' ', const Date &newBirthDate = Date(), const string &newIdNumber = "");

    ~People() = default; // destructor

private:
    int id;
    string idNumber;
    char gender;
    Date birthDate;
};

inline void People::displayPeople() const
{
    cout << "ID: " << id << "\nGender: " << gender << "\nBirth Date: ";
    birthDate.displayDate();
    cout << "\nID Number: " << idNumber << endl;
}

void People::updatePeopleInfo(int newId, char newGender, const Date &newBirthDate, const string &newIdNumber)
{
    id = newId;
    gender = newGender;
    birthDate = newBirthDate;
    idNumber = newIdNumber;
}


int main()
{
    cout << "Welcome to HR management!" << endl;
    People People1(1, 'M', Date(1, 1, 1990), "123456789");
    People1.displayPeople();

    People People2 = People1;
    People2.displayPeople();
    
    return 0;
}
