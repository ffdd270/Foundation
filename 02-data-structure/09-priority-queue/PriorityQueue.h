#pragma once
#include "../09-useful-heap/UsefulHeap.h"
using namespace heap;

namespace priorityqueue
{
    template <typename T>
    class PriorityQueue : public Heap<T>
    {
    public:
        using Heap<T>::Heap;

        bool IsEmpty();

        void Enqueue(T data);
        T    Dequeue();
    };

    template<typename T>
    bool PriorityQueue<T>::IsEmpty()
    {
        return Heap<T>::IsEmpty();
    }

    template<typename T>
    void PriorityQueue<T>::Enqueue(T data)
    {
        Heap<T>::Insert(data);
    }

    template<typename T>
    T PriorityQueue<T>::Dequeue()
    {
        return Heap<T>::Delete();
    }
}
