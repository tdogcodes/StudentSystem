#include "roster.h"
#include <vector>

Roster::Roster() : numStudents(0) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        classRosterArray[i] = nullptr; // initialize all pointers to nullptr
    }
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        delete classRosterArray[i]; // frees memory for every student in the classRosterArray
    }
}

//converts enum value to string
string degreeProgramToString(DegreeProgram degreeProgram) {
    switch (degreeProgram) {
    case SECURITY: return "SECURITY";
    case NETWORK: return "NETWORK";
    case SOFTWARE: return "SOFTWARE";
    default: return "UNKNOWN";
    }
}
//converts string to enum value
DegreeProgram convertToDegreeProgram(const string& degreeProgramStr) {
    if (degreeProgramStr == "SECURITY") {
        return SECURITY;
    }
    else if (degreeProgramStr == "NETWORK") {
        return NETWORK;
    }
    else if (degreeProgramStr == "SOFTWARE") {
        return SOFTWARE;
    }
    else {
        throw invalid_argument("Invalid degree program: " + degreeProgramStr);
    }
}

//Part E.2 parses and adds each student from the studentDataTable to classRosterArray
void Roster::parseAndAddStudents(const string studentDataTable[], int size) {
    for (int i = 0; i < size; i++) {
        string data = studentDataTable[i];
        vector<string> tokens;
        size_t start = 0;
        size_t end = data.find(',');

        while (end != string::npos) {
            tokens.push_back(data.substr(start, end - start));
            start = end + 1;
            end = data.find(',', start);
        }
        tokens.push_back(data.substr(start)); // adds the last item without comma at the end

        string studentId = tokens[0];
        string firstName = tokens[1];
        string lastName = tokens[2];
        string email = tokens[3];
        int age = stoi(tokens[4]);
        int daysInCourse1 = stoi(tokens[5]);
        int daysInCourse2 = stoi(tokens[6]);
        int daysInCourse3 = stoi(tokens[7]);
        DegreeProgram degreeProgram = convertToDegreeProgram(tokens[8]);

        // adds student to the roster
        add(studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
}

// add a student to the roster
void Roster::add(string studentId, string firstName, string lastName, string email,
    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    if (numStudents < MAX_STUDENTS) {
        int daysInCourses[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        classRosterArray[numStudents] = new Student(studentId, firstName, lastName, email,
            age, daysInCourses, degreeProgram);
        numStudents++;
    }
    else {
        cout << "Error: Roster is full. Cannot add more students." << endl;
    }
}

// Remove a student from the roster by student ID
void Roster::remove(string studentId) {
    bool found = false;
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getStudentId() == studentId) {
            delete classRosterArray[i]; // Frees memory for the student
            classRosterArray[i] = nullptr; // Set the pointer to nullptr
            found = true;

            // Shift remaining students to fill the gap
            for (int j = i; j < numStudents - 1; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            numStudents--;
            cout << "Student with ID " << studentId << " removed." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Error: Student with ID " << studentId << " not found." << endl;
    }
}

/* Prints all students in the roster, loops over numStudents which is
 the number of students in classRosterArray, initalized in the constructor Ln:4 */
void Roster::printAll() const {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr) { 
            classRosterArray[i]->print();
        }
    }
}

// Print the average days in course for a specific student
void Roster::printAverageDaysInCourse(string studentId) const {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getStudentId() == studentId) {
            const int* days = classRosterArray[i]->getDaysInClasses();
            int average = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID: " << studentId << ", Average Days in Courses: " << average << endl;
            return;
        }
    }
    cout << "Error: Student with ID " << studentId << " not found." << endl;
}

// Print invalid email addresses
void Roster::printInvalidEmails() const {
    for (int i = 0; i < numStudents; i++) {
        string email = classRosterArray[i]->getEmail();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << "Invalid Email: " << email << endl;
        }
    }
}

// Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            cout << endl;
        }
    }
}