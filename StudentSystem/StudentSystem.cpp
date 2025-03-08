#include <iostream>
#include "student.h"

using namespace std;

int main()
{
    // Initialize days in classes array
    int daysInClasses[] = { 30, 25, 20 };

    // Create a Student object
    Student student("A12345", "John", "Doe", "john.doe@example.com", 20, daysInClasses, "Computer Science");

    // Print student details
    cout << "Initial Student Details:" << endl;
    student.print();
    cout << endl;

    // Update student details using setters
    student.setStudentId("B67890");
    student.setFirstName("Jane");
    student.setLastName("Smith");
    student.setEmail("jane.smith@example.com");
    student.setAge(21);

    int newDaysInClasses[] = { 28, 24, 22 };
    student.setDaysInClasses(newDaysInClasses);

    student.setDegreeProgram("Electrical Engineering");

    // Print updated student details
    cout << "Updated Student Details:" << endl;
    student.print();

}
