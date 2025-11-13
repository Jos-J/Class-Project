#include <iostream>
#include <sstream>
#include <iomanip>
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
    for (int i = 0; i < lastIndex; i++)
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
    // Print header
    cout << left
         << setw(5) << "ID"
         << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(25) << "Email"
         << setw(5) << "Age"
         << setw(15) << "daysInCourse"
         << setw(20) << "Degree Program"
         << endl;

    cout << string(110, '-') << endl;

    // Print each student
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    // Print header
    cout << left
         << setw(10) << "Student ID"
         << setw(25) << " Average Days in Course"
         << endl;
    cout << string(35, '-') << endl;

    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i] != nullptr &&
            classRosterArray[i]->getStudentID() == studentID)
        {
            const int *days = classRosterArray[i]->getDaysInCourse();
            double average = (days[0] + days[1] + days[2]) / 3.0;

            cout << left
                 << setw(10) << studentID
                 << setw(25) << average
                 << endl;

            cout << endl; // blank line between rows
            break;
        }
    }
}

void Roster::printInvalidEmails()
{
    // Print header
    cout << left
         << setw(30) << "Invalid Email Addresses"
         << endl;
    cout << string(30, '-') << endl;

    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i] != nullptr)
        {
            string email = classRosterArray[i]->getEmailAddress();
            if (email.find(' ') != string::npos ||
                email.find('@') == string::npos ||
                email.find('.') == string::npos)
            {
                cout << left << setw(30) << email << endl;
            }
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    // Print header
    cout << left
         << setw(5) << "ID"
         << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(25) << "Email"
         << setw(5) << "Age"
         << setw(15) << "daysInCourse"
         << setw(20) << "Degree Program"
         << endl;
    cout << string(110, '-') << endl;

    // Print students in the selected degree program
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
