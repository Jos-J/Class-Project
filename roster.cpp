#include <iostream>
#include <sstream>
#include "roster.h"
using namespace std;

// --- Parse studentData---//
void Roster::parse(string studentData)
{

    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    string degreeStr = studentData.substr(lhs);

    DegreeProgram degreeProgram;
    if (degreeStr == "SECURITY")
        degreeProgram = SECURITY;
    else if (degreeStr == "NETWORK")
        degreeProgram = NETWORK;
    else if (degreeStr == "SOFTWARE")
        degreeProgram = SOFTWARE;
    else if (degreeStr == "COMPUTERSCI")
        degreeProgram = COMPUTERSCI;

    // add the student
    add(studentID, firstName, lastName, emailAddress, age,
        daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    lastIndex++;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}

void Roster::remove(string studentID)
{
    bool found = false;
    for (int i = 0; i < numStudents; i++)
    {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            cout << "Student " << studentID << " removed." << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Error: Student ID " << studentID << " not found." << endl;
    }
}

void Roster::printAll()
{
    for (int i = 0; i < numStudents; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i] != nullptr &&
            classRosterArray[i]->getStudentID() == studentID)
        {

            const int *days = classRosterArray[i]->getDaysInCourse();
            cout << "Student ID: " << studentID
                 << ", average days in course: "
                 << (days[0] + days[1] + days[2]) / 3.0 << endl;
            break;
        }
    }
}

void Roster::printInvalidEmails()
{
    cout << "Invalid email addresses:" << endl;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            string email = classRosterArray[i]->getEmailAddress();
            if (email.find(' ') != string::npos ||
                email.find('@') == string::npos ||
                email.find('.') == string::npos)
            {

                cout << email << endl;
            }
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i] != nullptr &&
            classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {

            classRosterArray[i]->print();
        }
    }
}

// ----- Destructor -----
Roster::~Roster()
{
    for (int i = 0; i < numStudents; i++)
    {
        delete classRosterArray[i]; // Calls Student destructor
        classRosterArray[i] = nullptr;
    }
}
