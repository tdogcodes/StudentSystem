#include "roster.h"
#include <vector>

//constructor initalized
Roster::Roster() : numStudents(0) {
	for (int i = 0; i < MAX_STUDENTS; i++) {
		classRosterArray[i] = nullptr;
	}
}

