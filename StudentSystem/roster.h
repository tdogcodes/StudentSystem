#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//Part E, defining the variables and methods for the Roster class
class Roster {
	private:
		//Part E.1 defining classRosterArray
		static const int MAX_STUDENTS = 5;
		Student* classRosterArray[MAX_STUDENTS];
		int numStudents;

	public:
		Roster();
		~Roster();

		//Part E.3 defining roster methods

		//used with add() to parse data before adding the student to the roster
		void parseAndAddStudents(const string studentDataTable[], int size);

		void add(string studentId, string firstName, string lastName, string email,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

		void remove(string studentId);

		void printAll() const;

		void printAverageDaysInCourse(string studentId) const;

		void printInvalidEmails() const;

		void printByDegreeProgram(DegreeProgram degreeProgram) const;

};

DegreeProgram convertToDegreeProgram(const std::string& degreeProgramStr);
std::string degreeProgramToString(DegreeProgram degreeProgram);

#endif