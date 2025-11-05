#pragma once
#include "student.h"
#include <string>

using std::string;
// roster class//
class Roster {
public:
const static int numStudents = 5;
Student* classRosterArray[numStudents];

private:
int lastIndex = -1;

public:
void parse(string studentData);
void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
void remove(string studentID);
void printAll();
void printAverageDaysInCourse(string studentID);
void printInvalidEmails();
void printByDegreeProgram(DegreeProgram degreeProgram);

~Roster(); 

};
