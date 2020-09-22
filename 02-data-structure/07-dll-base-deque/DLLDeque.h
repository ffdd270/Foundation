#pragma once

namespace dlldeque
{
    template <typename T>
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };

    template <typename T>
    class DLLDeque
    {
    public:
        DLLDeque() : head(nullptr), tail(nullptr) {}

        bool IsEmpty();

        void AddFirst(T data);
        void AddLast(T data);

        T RemoveFirst();
        T RemoveLast();

        T GetFirst();
        T GetLast();

    private:
        Node<T>* head;
        Node<T>* tail;
    };

    template<typename T>
    bool DLLDeque<T>::IsEmpty()
    {
        return (head == nullptr);
    }

    template<typename T>
    void DLLDeque<T>::AddFirst(T data)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;

        if(IsEmpty())
            tail = newNode;
        else
            head->prev = newNode;

        head = newNode;
    }

    template<typename T>
    void DLLDeque<T>::AddLast(T data)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->prev = tail;
        newNode->next = nullptr;

        if(IsEmpty())
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    template<typename T>
    T DLLDeque<T>::RemoveFirst()
    {
        if(IsEmpty() == true)
        {
            throw("Deque Memory Error");
        }

        Node<T>* rnode = head;
        T rdata = rnode->data;

        head = head->next;
        delete rnode;

        if(head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        return rdata;
    }

    template<typename T>
    T DLLDeque<T>::RemoveLast()
    {
        if(IsEmpty() == true)
        {
            throw("Deque Memory Error");
        }

        Node<T>* rnode = tail;
        T rdata = rnode->data;

        tail = tail->prev;
        delete rnode;

        if(tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;

        return rdata;
    }

    template<typename T>
    T DLLDeque<T>::GetFirst()
    {
        if(IsEmpty() == true)
        {
            throw("Deque Memory Error");
        }

        return head->data;
    }

    template<typename T>
    T DLLDeque<T>::GetLast()
    {
        if(IsEmpty() == true)
        {
            throw("Deque Memory Error");
        }

        return tail->data;
    }
}
