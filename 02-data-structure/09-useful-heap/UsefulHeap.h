#pragma once

namespace heap
{
    constexpr int HEAP_LEN = 100;

    template <typename T>
    class Heap
    {
    public:
        explicit Heap(int (*priorityComp)(T, T)) : numOfData(0) , priorityComp(priorityComp) {}

        static int GetParentIndex(int index);
        static int GetLeftChildIndex(int index);
        static int GetRightChildIndex(int index);

        int GetHighPriorityChildIndex(int index);

        bool IsEmpty();
        void Insert(T datay);
        T    Delete();

    private:
        int numOfData;
        T heapArray[HEAP_LEN];
        int (*priorityComp)(T d1, T d2);
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
            if(priorityComp(heapArray[GetLeftChildIndex(index)], heapArray[GetRightChildIndex(index)]) > 0)
                return GetLeftChildIndex(index);

            else
                return GetRightChildIndex(index);
        }
    }

    template<typename T>
    bool Heap<T>::IsEmpty()
    {
        return (numOfData == 0);
    }

    template<typename T>
    void Heap<T>::Insert(T data)
    {
        int index = numOfData + 1;

        while (index != 1)
        {
            if(priorityComp(data, heapArray[GetParentIndex(index)]) > 0)
            {
                heapArray[index] = heapArray[GetParentIndex(index)];
                index = GetParentIndex(index);
            }

            else
                break;
        }

        heapArray[index] = data;
        numOfData += 1;
    }

    template<typename T>
    T Heap<T>::Delete()
    {
        T returnData = heapArray[1];
        T lastElement = heapArray[numOfData];

        int parentIndex = 1;
        int childIndex;

        while(childIndex = GetHighPriorityChildIndex(parentIndex))
        {
            if(priorityComp(lastElement, heapArray[childIndex]) >= 0)
                break;

            heapArray[parentIndex] = heapArray[childIndex];
            parentIndex = childIndex;
        }

        heapArray[parentIndex] = lastElement;
        numOfData -= 1;
        return returnData;
    }
}

