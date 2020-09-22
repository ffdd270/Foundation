#pragma once

namespace dllist
{
    template <typename T>
    struct Node
    {
        T data;
        Node* prev;
        Node* next;
    };

    template <typename T>
    class DLList
    {
    public:
        DLList();

        void Insert(T data);
        T Remove();

        bool First(T* data);
        bool Last(T* data);
        bool Next(T* data);
        bool Previous(T* data);

        bool isEmpty();
        int Count();

    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* cur;
        int numOfData;
    };

    template<typename T>
    DLList<T>::DLList()
    {
        head = new Node<T>;
        tail = new Node<T>;

        head->prev = nullptr;
        head->next = tail;

        tail->prev = head;
        tail->next = nullptr;

        numOfData = 0;
    }

    template<typename T>
    void DLList<T>::Insert(T data)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;

        newNode->prev = tail->prev;
        newNode->next = tail;

        tail->prev->next = newNode;
        tail->prev = newNode;

        if(isEmpty())
            cur = newNode;

        numOfData++;
    }

    template<typename T>
    T DLList<T>::Remove()
    {
        Node<T>* removeNode = cur;
        T removeData = removeNode->data;

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        cur = cur->prev;

        delete removeNode;
        numOfData--;
        return removeData;
    }

    template<typename T>
    bool DLList<T>::First(T* data)
    {
        if (head->next == tail)
            return false;

        cur = head->next;
        *data = cur->data;
        return true;
    }

    template <typename T>
    bool DLList<T>::Last(T* data)
    {
        if(tail->prev == head)
            return false;

        cur = tail->prev;
        *data = cur->data;
        return true;
    }

    template<typename T>
    bool DLList<T>::Next(T* data)
    {
        if (cur->next == tail)
            return false;

        cur = cur->next;
        *data = cur->data;
        return true;
    }

    template<typename T>
    bool DLList<T>::Previous(T* data)
    {
        if (cur->prev == head)
            return false;

        cur = cur->prev;
        *data = cur->data;
        return true;
    }

    template<typename T>
    bool DLList<T>::isEmpty()
    {
        return (numOfData == 0);
    }

    template<typename T>
    int DLList<T>::Count()
    {
        return numOfData;
    }
}
