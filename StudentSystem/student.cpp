#include "student.h"

//Part D, functionality of the methods from the header

//constructor implementation
Student::Student(string studentId, string firstName, string lastName,
    string email, int age, int daysInClasses[], string degreeProgram) {
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
//print implementation
void Student::print() const {
    cout << "Student ID: " << studentId << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Email: " << email << endl;
    cout << "Age: " << age << endl;
    cout << "Days in Classes: {" << daysInClasses[0] << ", "
        << daysInClasses[1] << ", " << daysInClasses[2] << "}" << endl;
    cout << "Degree Program: " << degreeProgram << endl;
}