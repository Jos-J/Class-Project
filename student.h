#pragma once
#include <string>
#include "degree.h"

//--create student class--

class Student {
private:
    // Variables
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // ------- Constructors -----
    Student();
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

    //-------Getters----------
    // ------- Getters ----------
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    const int *getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    //------- Setters----------
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emaildAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    //---------Print Funciton----------

    void print() const;

    ~Student();
};