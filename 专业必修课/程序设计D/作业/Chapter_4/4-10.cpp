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

class Staff
{
public:
    Staff() = default; // default constructor
    Staff(int id, char gender, const Date &birthDate, const string &idNumber)
        : id(id), gender(gender), birthDate(birthDate), idNumber(idNumber) {} // constructor
    Staff(const Staff &other)
        : id(other.id), gender(other.gender), birthDate(other.birthDate), idNumber(other.idNumber) {} // copy constructor
    void displayStaff() const;
    void updateStaffInfo(int newId = 0, char newGender = ' ', const Date &newBirthDate = Date(), const string &newIdNumber = "");

    ~Staff() = default; // destructor

private:
    int id;
    string idNumber;
    char gender;
    Date birthDate;
};

inline void Staff::displayStaff() const
{
    cout << "ID: " << id << "\nGender: " << gender << "\nBirth Date: ";
    birthDate.displayDate();
    cout << "\nID Number: " << idNumber << endl;
}

void Staff::updateStaffInfo(int newId, char newGender, const Date &newBirthDate, const string &newIdNumber)
{
    id = newId;
    gender = newGender;
    birthDate = newBirthDate;
    idNumber = newIdNumber;
}


int main()
{
    cout << "Welcome to HR management!" << endl;
    Staff Staff1(1, 'M', Date(1, 1, 1990), "123456789");
    Staff1.displayStaff();

    Staff Staff2 = Staff1;
    Staff2.displayStaff();
    
    return 0;
}
