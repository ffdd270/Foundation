#pragma once
#include <string>
#include <iostream>

///////////
// Value //
///////////

struct StudentInfo
{
    StudentInfo(int studentID, const std::string& name, double grade) : studentID(studentID), name(name), grade(grade) {}
    int studentID;
    std::string name;
    double grade;

    void ShowInfo() const noexcept;
};

void StudentInfo::ShowInfo() const noexcept
{
    std::cout << "Name : " << name << "\nGrade : " << grade << std::endl << std::endl;
}

///////////
// Slot  //
///////////

enum class SlotStatus {EMPTY, DELETED, INUSE};

template <typename Key, typename Value>
struct Slot
{
    Key key;
    Value value;
    SlotStatus status;
};


///////////
// Table //
///////////

constexpr int TABLE_LEN = 100;

template <typename Key, typename Value>
class Table
{
public:
    explicit Table(int (*)(Key));

    void Insert(Key key, Value value);
    Value Delete(Key key);
    Value Search(Key key);

private:
    Slot<Key, Value> table[TABLE_LEN];
    int (*hashFunction)(Key);
};

template<typename Key, typename Value>
Table<Key, Value>::Table(int (*hf)(Key))
{
    for(auto elem : table)
        elem.status = SlotStatus::EMPTY;

    hashFunction = hf;
}

template<typename Key, typename Value>
void Table<Key, Value>::Insert(Key key, Value value)
{
    int hashValue = hashFunction(key);
    table[hashValue].key = key;
    table[hashValue].value = value;
    table[hashValue].status = SlotStatus::INUSE;
}

template<typename Key, typename Value>
Value Table<Key, Value>::Delete(Key key)
{
    int hashValue = hashFunction(key);

    if(table[hashValue].status != SlotStatus::INUSE)
    {
        return nullptr;
    }
    else
    {
        table[hashValue].status = SlotStatus::DELETED;
        return table[hashValue].value;
    }
}

template<typename Key, typename Value>
Value Table<Key, Value>::Search(Key key)
{
    int hashValue = hashFunction(key);

    if(table[hashValue].status != SlotStatus::INUSE)
    {
        return nullptr;
    }
    else
    {
        return table[hashValue].value;
    }
}
