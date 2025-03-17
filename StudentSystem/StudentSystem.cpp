#include <iostream>
#include "roster.h"

using namespace std;

int main()
{
    // F.1 Print course information
    cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 012365303" << endl;
    cout << "Name: Tracy Sandoval" << endl;
    cout << endl;

    //F.2 Create a Roster object
    Roster classRoster;

    //F.3 Student data table
    const string studentDataTable[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tracy,Sandoval,tsando11@wgu.edu,22,20,15,25,SOFTWARE"
    };

    int numStudents = sizeof(studentDataTable) / sizeof(studentDataTable[0]);
    classRoster.parseAndAddStudents(studentDataTable, numStudents);

    // F.4 Perform required operations
    cout << "Printing all students:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Printing invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Printing average days in course for each student:" << endl;
    for (int i = 0; i < numStudents; i++) {
        string studentId = classRoster.getClassRosterArray()[i]->getStudentId();
        classRoster.printAverageDaysInCourse(studentId);
    }
    cout << endl;

    cout << "Printing students by degree program (SOFTWARE):" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing student with ID A3:" << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "Printing all students after removal:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Attempting to remove student with ID A3 again:" << endl;
    classRoster.remove("A3");
    cout << endl;

    // F.5 Destructor will be called automatically when classRoster goes out of scope
    cout << "End of program. Memory cleanup will occur automatically." << endl;


}
