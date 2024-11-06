#include <iostream>
#include <iomanip> // parameterized stream mani pulators
using namespace std;
// include definition of class GradeBook from GradeBook.h
#include "GradeBook.h"
// two- argument constructor initializes courseName and grades array
GradeBook::GradeBook(string name, const int gradesArray[][tests])
{
    setCourseName(name); // initialize courseName
    // copy grades from gradeArray to grades
    for (int student = 0; student < students; student++)
        for (int test = 0; test < tests; test++)
            grades[student][test] = gradesArray[student][test];
} // end two-argument GradeBook constructor
// function to set the course name
void GradeBook::setCourseName(string name)
{
    courseName = name; // store the course name
} // end function setCourseName
// function to retrieve the course name
string GradeBook::getCourseName()
{
    return courseName;
} // end function getCourseName
// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
    // this statement calls getCourseName to get the
    // name of the course this GradeBook represents
    cout << "Welcome to the grade book for\n"
         << getCourseName() << "! "
         << endl;
} // end function di splayMessage
// perform various operations on the data
void GradeBook::processGrades()
{
    outputGrades(); // output grades array
    // ca1l functions getMinimum and getMaximum
    cout << "\nLowest grade in the grade book is" << getMinimum()
         << "\nHighest grade in the grade book is" << getMaximum() << endl;
    outputBarChart(); // display distribution chart of grades on a11 tests
} // end function processGrades

// find minimum grade in the entire gradebook
int GradeBook::getMinimum()
{
    int lowGrade = 100; // assume lowest grade is 100
    // 1oop through rows of grades array
    for (int student = 0; student < students; student++)
    {
        // 1oop through columns of current row
        for (int test = 0; test < tests; test++)
        {
            // if current grade less than lowGrade, assign it to lowGrade
            if (grades[student][test] < lowGrade)
                lowGrade = grades[student][test]; // new lowest grade
        }                                         // end inner for
    }                                             // end outer for
    return lowGrade;                              // return 1owest grade
} // end function getMi ni mum

// find maximum grade in the entire gradebook
int GradeBook::getMaximum()
{
    int highGrade = 0; // assume highest grade is 0
    // 1oop through rows of grades array
    for (int student = 0; student < students; student++)
    {
        // 1oop through columns of current row
        for (int test = 0; test < tests; test++)
        {
            // if current grade greater than highGrade, assign to hi ghGrade
            if (grades[student][test] > highGrade)
                highGrade = grades[student][test]; // new highest grade
        }                                          // end inner for
    }                                              // end outer for
    return highGrade;                              // return highest grade
} // end function getMaxi mum
// determine average grade for particular set of grades
double GradeBook ::getAverage(const int setOfGrades[], const int grades)
{
    int total = 0; // initialize tota1
    // sum grades in array
    for (int grade = 0; grade < grades; grade++)
        total += setOfGrades[grade];
    // return average of grades
    return static_cast<double>(total) / grades;
} // end function getAverage
// output bar chart displaying grade distri buti on
void GradeBook::outputBarChart()
{
    cout << "\nOvera11 grade distribution:" << endl;
    // stores frequency of grades in each range of 10 grades
    const int frequencySize = 11;
    int frequency[frequencySize] = {}; // initialize elements to 0
    // for each grade, increment the appropriate frequency
    for (int student = 0; student < students; student++)
        for (int test = 0; test < tests; test++)
            ++frequency[grades[student][test] / 10];
    // for each grade frequency， print bar in chart
    for (int count = 0; count < frequencySize; count++)
    {
        // output bar labe1 ("0-9:"， ... "90-99:"， "100:” )
        if (count == 0)
            cout << "0 - 9: ";
        else if (count == 10)
            cout << "100: ";
        else
            cout << count * 10 << "-" << (count * 10) + 9 << ":";
        // print bar of asterisks
        for (int stars = 0; stars < frequency[count]; stars++)
            cout << '*';

        cout << endl; // start a new1 ine of output
    }                 // end outer for
} // end function outputBarChart

// output the contents of the grades array
void GradeBook::outputGrades()
{
    cout << "\nThe grades are:\n\n";
    cout << "                      "; // align column heads
    // create a column heading for each of the tests
    for (int test = 0; test < tests; test++)
        cout << "Test" << test + 1 << "  ";
    cout << "Average" << endl; // student average co1 umn headi ng
    // create rows/co1umns of text representing array grades
    for (int student = 0; student < students; student++)
    {
        cout << "Student"
             << setw(2) << student + 1;
        // output student' s grades
        for (int test = 0; test < tests; test++)
            cout << setw(8) << grades[student][test];
        // ca11 member function getAverage to calculate student's average;
        // pass row of grades and the value of tests as the arguments
        double average = getAverage(grades[student], tests);
        cout << setw(9) << setprecision(2) << fixed << average << endl;
    } // end outer for
} // end function outputGrades
