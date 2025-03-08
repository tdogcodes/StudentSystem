#include <iostream>
#include "roster.h"

using namespace std;

int main()
{
    // Student data table
    const string studentDataTable[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Tracy,Sandoval,tsando11@wgu.edu,22,20,15,25,SOFTWARE"
    };

    // Create a Roster object
    Roster roster;

    // Parse and add students from the studentDataTable
    roster.parseAndAddStudents(studentDataTable, 5);

    // Print all students
    cout << "All Students:" << endl;
    roster.printAll();
    cout << endl;

    // Print invalid emails
    cout << "Invalid Emails:" << endl;
    roster.printInvalidEmails();
    cout << endl;

    // Print average days in course for each student
    cout << "Average Days in Course:" << endl;
    for (int i = 0; i < 5; i++) {
        string studentId = "A" + to_string(i + 1);
        roster.printAverageDaysInCourse(studentId);
    }
    cout << endl;

    // Print students by degree program
    cout << "Students in SOFTWARE Program:" << endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    // Remove a student
    cout << "Removing Student A3:" << endl;
    roster.remove("A3");
    cout << endl;

    // Print all students after removal
    cout << "All Students After Removal:" << endl;
    roster.printAll();

}
