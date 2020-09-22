#include <iostream>
#include "ChainingHash.h"
#include "StudentInfo.h"

using namespace table;

int SimpleHashFunction(int key)
{
    return key % 100;
}

int main()
{
    Table<int, StudentInfo*> studentTable(SimpleHashFunction);

    StudentInfo* newStudentInfo;
    StudentInfo* searchStudentInfo;
    StudentInfo* removeStudentInfo;

    newStudentInfo = new StudentInfo(20803'301, "Weny", 2, "Digipen");
    studentTable.Insert(newStudentInfo->studentID, newStudentInfo);

    newStudentInfo = new StudentInfo(20803'321, "Kesh", 2, "Digipen");
    studentTable.Insert(newStudentInfo->studentID, newStudentInfo);

    newStudentInfo = new StudentInfo(20803'353, "Yena", 2, "Digipen");
    studentTable.Insert(newStudentInfo->studentID, newStudentInfo);

    newStudentInfo = new StudentInfo(20803'101, "Sina", 2, "Digipen");
    studentTable.Insert(newStudentInfo->studentID, newStudentInfo);

    newStudentInfo = new StudentInfo(20803'301, "Frody", 2, "Digipen");
    studentTable.Insert(newStudentInfo->studentID, newStudentInfo);

    newStudentInfo = new StudentInfo(20804'321, "Naru", 1, "GameMobile");
    studentTable.Insert(newStudentInfo->studentID, newStudentInfo);


    searchStudentInfo = studentTable.Search(20803'301);
    if(searchStudentInfo != nullptr)
        searchStudentInfo->printInfo();
    else
        std::cout << "Not Founded!" << std::endl;

    searchStudentInfo = studentTable.Search(20803'321);
    if(searchStudentInfo != nullptr)
        searchStudentInfo->printInfo();
    else
        std::cout << "Not Founded!" << std::endl;

    searchStudentInfo = studentTable.Search(20803'353);
    if(searchStudentInfo != nullptr)
        searchStudentInfo->printInfo();
    else
        std::cout << "Not Founded!" << std::endl;

    searchStudentInfo = studentTable.Search(20803'101);
    if(searchStudentInfo != nullptr)
        searchStudentInfo->printInfo();
    else
        std::cout << "Not Founded!" << std::endl;

    searchStudentInfo = studentTable.Search(20803'301);
    if(searchStudentInfo != nullptr)
        searchStudentInfo->printInfo();
    else
        std::cout << "Not Founded!" << std::endl;

    searchStudentInfo = studentTable.Search(20804'321);
    if(searchStudentInfo != nullptr)
        searchStudentInfo->printInfo();
    else
        std::cout << "Not Founded!" << std::endl;

    return 0;
}