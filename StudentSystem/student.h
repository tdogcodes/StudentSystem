#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

//Part D, defining the variables and methods for the Student class
class Student {
private:
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInClasses[3];
    string degreeProgram;

public:
    //constructor definition
    Student(string studentId, string firstName, string lastName,
        string email, int age, int daysInClasses[], string degreeProgram);

    //accessor definitions
    string getStudentId() const { return studentId; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getEmail() const { return email; }
    int getAge() const { return age; }
    const int* getDaysInClasses() const { return daysInClasses; }
    string getDegreeProgram() const { return degreeProgram; }

    //mutator definitions
    void setStudentId(string studentId) {
        this->studentId = studentId;
    }
    void setFirstName(string firstName) {
        this->firstName = firstName;
    }
    void setLastName(string lastName) {
        this->lastName = lastName;
    }
    void setEmail(string email) {
        this->email = email;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setDaysInClasses(const int daysInClasses[3]) {
        for (int i = 0; i < 3; i++) {
            this->daysInClasses[i] = daysInClasses[i];
        }
    }
    void setDegreeProgram(string degreeProgram) {
        this->degreeProgram = degreeProgram;
    }
    // print definition
    void print() const;
};

#endif