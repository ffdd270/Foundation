#pragma once

namespace heap
{
    constexpr int HEAP_LEN = 100;

    template <typename T>
    struct HeapElement
    {
        int priority;
        T data;
    };

    template <typename T>
    class Heap
    {
    public:
        Heap() : numOfData(0) {}

        static int GetParentIndex(int index);
        static int GetLeftChildIndex(int index);
        static int GetRightChildIndex(int index);

        int GetHighPriorityChildIndex(int index);

        bool IsEmpty();
        void Insert(T data, int priority);
        T    Delete();

    private:
        int numOfData;
        HeapElement<T> heapArray[HEAP_LEN];
    };

    template<typename T>
    int Heap<T>::GetParentIndex(int index)
    {
        return index / 2;
    }

    template<typename T>
    int Heap<T>::GetLeftChildIndex(int index)
    {
        return index * 2;
    }

    template<typename T>
    int Heap<T>::GetRightChildIndex(int index)
    {
        return GetLeftChildIndex(index) + 1;
    }

    template<typename T>
    int Heap<T>::GetHighPriorityChildIndex(int index)
    {
        if(GetLeftChildIndex(index) > numOfData)
            return 0;

        else if (GetLeftChildIndex(index) == numOfData)
            return GetLeftChildIndex(index);

        else
        {
            if(heapArray[GetLeftChildIndex(index)].priority > heapArray[GetRightChildIndex(index)].priority)
                return GetRightChildIndex(index);

            else
                return GetLeftChildIndex(index);
        }
    }

    template<typename T>
    bool Heap<T>::IsEmpty()
    {
        return (numOfData == 0);
    }

    template<typename T>
    void Heap<T>::Insert(T data, int priority)
    {
        int index = numOfData + 1;
        HeapElement<T> newElement = {priority, data};

        while (index != 1)
        {
            if(priority < heapArray[GetParentIndex(index)].priority)
            {
                heapArray[index] = heapArray[GetParentIndex(index)];
                index = GetParentIndex(index);
            }

            else
                break;
        }

        heapArray[index] = newElement;
        numOfData += 1;
    }

    template<typename T>
    T Heap<T>::Delete()
    {
        T returnData = heapArray[1].data;
        HeapElement<T> lastElement = heapArray[numOfData];

        int parentIndex = 1;
        int childIndex;

        while(childIndex = GetHighPriorityChildIndex(parentIndex))
        {
            if(lastElement.priority <= heapArray[childIndex].priority)
                break;

            heapArray[parentIndex] = heapArray[childIndex];
            parentIndex = childIndex;
        }

        heapArray[parentIndex] = lastElement;
        numOfData -= 1;
        return returnData;
    }
}