#pragma once
#include <iostream>
#include <string>

struct StudentInfo
{
    StudentInfo(int studentID, const std::string& name, int grade, const std::string& department);

    int studentID;
    std::string name;
    int grade;
    std::string department;

    void printInfo();
};

StudentInfo::StudentInfo(int studentID, const std::string &name, int grade, const std::string &department) :
studentID(studentID), name(name), grade(grade), department(department) {}

void StudentInfo::printInfo()
{
    std::cout << "Student ID : " << studentID << ", name : " << name << " , " << department << "-" << grade << std::endl;
}
