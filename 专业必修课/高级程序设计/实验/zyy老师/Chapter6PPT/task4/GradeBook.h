#include <string> // program uses C++ Standard Library string class
using namespace std;
// GradeBook class definition
class GradeBook
{
public:
    // constant -- number of students who took the test
    static const int students = 10; // note public data
    // constructor initializes course name and array of grades
    GradeBook(string, const int[]);
    void setCourseName(string); // function to set the course name
    string getCourseName();     // function to retrieve the course name
    void displayMessage();      // display a welcome message
    void processGrades();       // perform various operations on the grade data
    int getMinimum();           // find the minimum grade for the test
    int getMaximum();           // find the maximum grade for the test
    double getAverage();        // determine the average grade for the test
    void outputBarChart();      // output bar chart of grade distri buti on
    void outputGrades();        // output the contents of the grades array
private:
    string courseName;    // course name for this grade book
    int grades[students]; // array of student grades
};                        // end class GradeBook
