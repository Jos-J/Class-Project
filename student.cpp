#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

// ----- Constructors -----
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < 3; i++)
        this->daysInCourse[i] = 0;
    this->degreeProgram = SOFTWARE; // default choice
}

Student::Student(string studentID, string firstName, string lastName,
                 string emailAddress, int age, int daysToComplete[],
                 DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++)
        this->daysInCourse[i] = daysToComplete[i];
    this->degreeProgram = degreeProgram;
}

// ----- Accessors -----
string Student::getStudentID() const { return studentID; }
string Student::getFirstName() const { return firstName; }
string Student::getLastName() const { return lastName; }
string Student::getEmailAddress() const { return emailAddress; }
int Student::getAge() const { return age; }
const int *Student::getDaysInCourse() const { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return degreeProgram; }

// ----- Mutators -----
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[])
{
    for (int i = 0; i < 3; i++)
        this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// ----- Print Function -----
void Student::print() const
{
    cout << left
         << setw(5) << studentID
         << setw(15) << firstName
         << setw(15) << lastName
         << setw(25) << emailAddress
         << setw(5) << age;

    // Print daysInCourse in fixed width
    cout << "{"
         << setw(3) << daysInCourse[0] << ", "
         << setw(3) << daysInCourse[1] << ", "
         << setw(3) << daysInCourse[2] << "}  ";

    // Degree program as readable text
    string degreeStr;
    switch (degreeProgram)
    {
    case SECURITY:
        degreeStr = "Security";
        break;
    case NETWORK:
        degreeStr = "Network";
        break;
    case SOFTWARE:
        degreeStr = "Software";
        break;
    case COMPUTERSCI:
        degreeStr = "Computer Science";
        break;
    }
    cout << setw(20) << degreeStr << endl;
}
Student::~Student()
{
}
