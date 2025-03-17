#include "student.h"
#include "roster.h"

//Part D, functionality of the methods from the header

//constructor implementation
Student::Student(string studentId, string firstName, string lastName,
    string email, int age, int daysInClasses[], DegreeProgram degreeProgram) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->daysInClasses[i] = daysInClasses[i];
    }
    this->degreeProgram = degreeProgram;
}
//print implementation, formatted exactly as specified in E3c
void Student::print() const {
    cout << studentId << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {" << daysInClasses[0] << ", " << daysInClasses[1] << ", " << daysInClasses[2] << "}";
    cout << " Degree Program: " << degreeProgramToString(degreeProgram) << endl;
}              