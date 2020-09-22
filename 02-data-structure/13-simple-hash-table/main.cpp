#include <iostream>
#include "SimpleHash.h"

using namespace table;

int SimpleHashFunction(int key)
{
    return key % 100;
}

int main()
{
    Table<int, StudentInfo*> table(SimpleHashFunction);

    StudentInfo* ns;
    StudentInfo* ss;
    StudentInfo* rs;

    ns = new StudentInfo(20200004, "Weny", 4.3);
    table.Insert(ns->studentID, ns);

    ns = new StudentInfo(20200025, "Kesh", 4.5);
    table.Insert(ns->studentID, ns);

    ns = new StudentInfo(20200042, "Yena", 4.4);
    table.Insert(ns->studentID, ns);

    ss = table.Search(20200004);
    if(ss != nullptr)
        ss->ShowInfo();

    ss = table.Search(20200042);
    if(ss != nullptr)
        ss->ShowInfo();

    ss = table.Search(20200025);
    if(ss != nullptr)
        ss->ShowInfo();

    rs = table.Delete(20200004);
    delete rs;

    rs = table.Delete(20200025);
    delete rs;

    rs = table.Delete(20200042);
    delete rs;

    return 0;
}