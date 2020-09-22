#pragma once

namespace llqueue
{
    template <typename T>
    struct Node
    {
        T data;
        Node* next;
    };

    template <typename T>
    class LlQueue
    {
    public:
        LlQueue() : front(nullptr), rear(nullptr) {}

        bool IsEmpty();
        void Enqueue(T data);
        T    Dequeue();
        T    Peek();
    private:
        Node<T>* front;
        Node<T>* rear;
    };

    template<typename T>
    bool LlQueue<T>::IsEmpty()
    {
        return (front == nullptr);
    }

    template<typename T>
    void LlQueue<T>::Enqueue(T data)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        if(IsEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    template<typename T>
    T LlQueue<T>::Dequeue()
    {
        if(IsEmpty())
        {
            throw("Queue Memory Error!");
        }

        Node<T>* rnode = front;
        T rdata = rnode->data;
        front = front->next;

        delete rnode;
        return rdata;
    }

    template<typename T>
    T LlQueue<T>::Peek()
    {
        if(IsEmpty())
        {
            throw("Queue Memory Error!");
        }

        return front->data;
    }
}