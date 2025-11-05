#include <iostream>
#include "roster.h"
using namespace std;

int main()
{
    // 1. Print course info
    cout << "Course: L987 - fighting the good fight\n";
    cout << "Language: C++\n";
    cout << "Student ID: 2813308004\n";
    cout << "Name: John Stewart\n\n";

    // 2. Create Roster instance
    Roster classRoster;

    // 3. Student data
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,Steward,green.ring@Glatern.com,45,25,47,37,COMPUTERSCI"};

    // 3. Add each student to the roster
    for (int i = 0; i < Roster::numStudents; i++)
    {
        classRoster.parse(studentData[i]);
    }

    // 4. Demonstrate functionality

    cout << "Displaying all students:\n";
    classRoster.printAll();
    cout << endl;

    cout << "Displaying invalid emails:\n";
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "Displaying average days in course for each student:\n";
    for (int i = 0; i < Roster::numStudents; i++)
    {
        if (classRoster.classRosterArray[i] != nullptr)
        {
            string studentID = classRoster.classRosterArray[i]->getStudentID();
            classRoster.printAverageDaysInCourse(studentID);
        }
    }
    cout << endl;

    cout << "Displaying students in SOFTWARE degree program:\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing student A3:\n";
    classRoster.remove("A3");
    cout << endl;

    cout << "Displaying all students after removal:\n";
    classRoster.printAll();
    cout << endl;

    cout << "Attempting to remove student A3 again:\n";
    classRoster.remove("A3");
    cout << endl;

    // 5. Destructor will automatically be called when classRoster goes out of scope
    return 0;
}
