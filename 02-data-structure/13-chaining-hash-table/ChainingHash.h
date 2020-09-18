#pragma once
#include "../03-double-linked-list/DoubleLinkedList.h"

template <typename Key, typename Value>
struct Slot
{
    Key key;
    Value value;
};

constexpr int TABLE_LEN = 100;

template <typename Key, typename Value>
class Table
{
public:
    explicit Table(int(*hashFunction)(Key));

    void  Insert(Key key, Value value);
    Value Delete(Key key);
    Value Search(Key key);
private:
    DLList<Slot<Key, Value>> table[TABLE_LEN];
    int (*hashFunction)(Key key);
};

template<typename Key, typename Value>
Table<Key, Value>::Table(int (*hashFunction)(Key)) : hashFunction(hashFunction)
{
    for(auto& dllist : table)
        dllist = DLList<Slot<Key, Value>>();
}

template<typename Key, typename Value>
void Table<Key, Value>::Insert(Key key, Value value)
{
    int hashValue = hashFunction(key);
    Slot<Key, Value> newSlot = { key, value };

    if(Search(key) != nullptr)
    {
        std::cout << "Key Collision Occurred\n";
        return;
    }
    else
    {
        table[hashValue].Insert(newSlot);
    }
}

template<typename Key, typename Value>
Value Table<Key, Value>::Delete(Key key)
{
    int hashValue = hashFunction(key);
    Slot<Key, Value> currentSlot;

    if(table[hashValue].First(&currentSlot))
    {
        if(currentSlot.key == key)
        {
            table[hashValue].Remove();
            return currentSlot.value;
        }
        else
        {
            while(table[hashValue].Next(&currentSlot))
            {
                if(currentSlot.key == key)
                {
                    table[hashValue].Remove();
                    return currentSlot.value;
                }
            }
        }
    }

    return nullptr;
}

template<typename Key, typename Value>
Value Table<Key, Value>::Search(Key key)
{
    int hashValue = hashFunction(key);
    Slot<Key, Value> currentSlot;

    if(table[hashValue].First(&currentSlot))
    {
        if(currentSlot.key == key)
        {
            return currentSlot.value;
        }
        else
        {
            while(table[hashValue].Next(&currentSlot))
            {
                if(currentSlot.key == key)
                    return currentSlot.value;
            }
        }
    }

    return nullptr;
}