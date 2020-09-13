#pragma once
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node* next;
};

template <typename T>
class ListStack
{
public:
    ListStack() : head(nullptr) {} ;

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void push(T data)
    {
        Node<T>* newNode = new Node<T>;

        newNode->data = data;
        newNode->next = head;

        head = newNode;
    }

    T pop()
    {
        if(isEmpty() == true)
        {
            throw("Stack Memory Error");
        }

         Node<T>* rnode = head;
         T rdata = head->data;

         head = head->next;
         delete rnode;

         return rdata;
    }

    T peek()
    {
        if(isEmpty() == true)
        {
            throw("Stack Memory Error");
        }

        return head->data;
    }

private:
    Node<T>* head;
};