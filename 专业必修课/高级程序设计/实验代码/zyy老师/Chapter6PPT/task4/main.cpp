#include "GradeBook.h" // GradeBook class definition
// function main begins program execution
int main()
{
    // array of student grades
    int gradesArray[GradeBook::students] =
        {87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
    GradeBook myGradeBook(
        "CS101 Introduction to C++ Programming", 
        gradesArray);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
} // end main
