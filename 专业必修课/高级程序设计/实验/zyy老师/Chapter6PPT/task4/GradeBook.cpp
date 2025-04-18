#include <iostream>
#include <iomanip>
#include "GradeBook.h" // GradeBook class definition
using namespace std;
// constructor initializes courseName and grades array
GradeBook::GradeBook(string name, const int gradesArray[])
{
    setCourseName(name); // initialize courseName
    // copy grades from gradesArray to grades data member
    for (int grade = 0; grade < students; grade++)
        grades[grade] = gradesArray[grade];
} // end GradeBook constructor
// function to set the course name
void GradeBook::setCourseName(string name)
{
    courseName = name; // store the course name
} // end function setCours eName
// function to retrieve the course name
string GradeBook::getCourseName()
{
    return courseName;
} // end function getCourseName
// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
    // this statement ca11s getCourseName
    // to get the name of the course this GradeBook represents
    cout << "Welcome to the grade book for\n"
         << getCourseName() << " !" << endl;
} // end function di splayMessage
// perform various operations on the data
void GradeBook::processGrades()
{
    outputGrades(); // output grades array
    // display average of a11 grades and mi nimum and maximum grades
    cout << "\nClass average is "
         << setprecision(2) << fixed << getAverage() << " \nLowest grade is "
         << getMinimum()
         << "\nHighest grade is"
         << getMaximum() << endl;

    outputBarChart(); // print grade distri bution chart
} // end function processGrades

// find mini mum grade
int GradeBook ::getMinimum()
{
    int lowGrade = 100; // assume lowest grade is 100
    // 1oop through grades array
    for (int grade = 0; grade < students; grade++)
    {
        // if current grade 1 ower than 1 owGrade, assign it to 1 owGrade
        if (grades[grade] < lowGrade)
            lowGrade = grades[grade]; // new lowest grade
    }                                 // end for
    return lowGrade;                  // return 1 owest grade
} // end function getMi ni mum

// find maximum grade
int GradeBook::getMaximum()
{
    int highGrade = 0; // assume highest grade is 0
    // 1oop through grades array
    for (int grade = 0; grade < students; grade++)
    {
        // if current grade higher than highGrade, assign it to highGrade
        if (grades[grade] > highGrade)
            highGrade = grades[grade]; // newhighest grade
    }                                  // end for
    return highGrade;                  // return highest grade
} // end function getMaxi mum

// determine average grade for test
double GradeBook ::getAverage()
{
    int total = 0; // initialize total
    // sum grades in array
    for (int grade = 0; grade < students; grade++)
        total += grades[grade];
    // return average of grades
    return static_cast<double>(total) / students;
} // end function getAverage

  // output bar chart displaying grade distri buti on
void GradeBook::outputBarChart()
{
    cout << "\nGrade distribution:" << endl;

    // stores frequency of grades in each range of 10 grades
    const int frequencySize = 11;
    int frequency[frequencySize] = {}; // initialize elements to 0

    // for each grade， i ncrement the appropriate frequency
    for (int grade = 0; grade < students; grade++)
        frequency[grades[grade] / students]++;

    // for each grade frequency， print bar in chart
    for (int count = 0; count < frequencySize; count++)
    {
        // output bar 1abels ("0-9:"， ...， "90-99:", '100:" )
        if (count == 0)
            cout << " 0-9: ";
        else if (count == 10)
            cout << " 100: ";
        else
            cout << count * 10 << "-" << (count * 10) + 9 << ":";
        // print bar of asterisks
        for (int stars = 0; stars < frequency[count]; stars++)
            cout << " $ ";

        cout << endl; // start a new line of output
    }                 // end outer for
} // end function outputBarChart

// output the contents of the grades array
void GradeBook::outputGrades()
{
    cout << "\nThe grades are:\n\n";
    // output each student's grade
    for (int student = 0; student < students; student++)
        cout << "Student"
             << setw(2) << student + 1 << ":"
             << setw(3) << grades[student] << endl;
} // end function outputGrades
