#pragma once
#include <iostream>

namespace liststack
{
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
        ListStack() : head(nullptr) {}

        bool IsEmpty();

        void Push(T data);
        T Pop();
        T Peek();

    private:
        Node<T>* head;
    };

    template<typename T>
    bool ListStack<T>::IsEmpty()
    {
        return (head == nullptr);
    }

    template<typename T>
    void ListStack<T>::Push(T data)
    {
        Node<T>* newNode = new Node<T>;

        newNode->data = data;
        newNode->next = head;

        head = newNode;
    }

    template<typename T>
    T ListStack<T>::Pop()
    {
        if(IsEmpty() == true)
        {
            throw("Stack Memory Error");
        }

        Node<T>* rnode = head;
        T rdata = head->data;

        head = head->next;
        delete rnode;

        return rdata;
    }

    template<typename T>
    T ListStack<T>::Peek()
    {
        if(IsEmpty() == true)
        {
            throw("Stack Memory Error");
        }

        return head->data;
    }
}