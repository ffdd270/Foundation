#pragma once

namespace cqueue
{
    template <typename T>
    class CQueue
    {
    public:
        CQueue() : front(0), rear(0) {}

        bool IsEmpty();
        int  NextPosIndex(int pos);

        void Enqueue(T data);
        T    Dequeue();
        T    Peek();

    private:
        static constexpr int length = 100;

        int front;
        int rear;
        T   queArr[length];
    };

    template<typename T>
    bool CQueue<T>::IsEmpty()
    {
        return (front == rear);
    }

    template<typename T>
    int CQueue<T>::NextPosIndex(int pos)
    {
        if(pos == length - 1)
            return 0;

        return pos + 1;
    }

    template<typename T>
    void CQueue<T>::Enqueue(T data)
    {
        if(NextPosIndex(rear) == front)
        {
            throw("Queue Memory Error!");
        }

        rear = NextPosIndex(rear);
        queArr[rear] = data;
    }

    template<typename T>
    T CQueue<T>::Dequeue()
    {
        if(IsEmpty())
        {
            throw("Queue Memory Error!");
        }

        front = NextPosIndex(front);
        return queArr[front];
    }

    template<typename T>
    T CQueue<T>::Peek()
    {
        if(IsEmpty())
        {
            throw("Queue Memory Error!");
        }

        return queArr[NextPosIndex(front)];
    }
}
