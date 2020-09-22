#pragma once

template <typename T>
void BubbleSort(T arr[], int n)
{
    int i, j;
    T temp;

    for(i = 0; i < n - 1; ++i)
    {
        for(j = 0; j < (n - 1) - i; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template <typename T>
void SelectionSort(T arr[], int n)
{
    int i, j;
    int maxIndex;
    T temp;

    for(i = 0; i < n - 1; ++i)
    {
        maxIndex = i;

        for(j = i + 1; j < n; ++j)
        {
            if(arr[j] < arr[maxIndex])
                maxIndex = j;
        }

        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

template <typename T>
void InsertionSort(T arr[], int n)
{
    int i, j;
    T insertionData;

    for(i = 1; i < n; ++i)
    {
        insertionData = arr[i];

        for(j = i - 1; j >= 0; --j)
        {
            if(arr[j] > insertionData)
                arr[j + 1] = arr[j];

            else
                break;
        }

        arr[j + 1] = insertionData;
    }
}

#include "../09-useful-heap/UsefulHeap.h"
using namespace heap;

template <typename T>
int CompareHighPriority(T d1, T d2)
{
    return d2 - d1;
}

template <typename T>
void HeapSort(T arr[], int n)
{
    Heap<T> heap(CompareHighPriority);
    int i;

    for(i = 0; i < n; ++i)
        heap.Insert(arr[i]);

    for(i = 0; i < n; ++i)
        arr[i] = heap.Delete();
}

template <typename T>
void MergeTwoArr(T arr[], int begin, int mid, int end)
{
    int leftIndex = begin;
    int rightIndex  = mid + 1;
    int i;

    int* sortedArr= new int[end + 1];
    int sortedArrIndex = begin;

    while(leftIndex <= mid && rightIndex <= end)
    {
        if(arr[leftIndex] <= arr[rightIndex])
            sortedArr[sortedArrIndex] = arr[leftIndex++];

        else
            sortedArr[sortedArrIndex] = arr[rightIndex++];

        ++sortedArrIndex;
    }

    if(leftIndex > mid)
    {
        for(i = rightIndex; i <= end; ++i, ++sortedArrIndex)
            sortedArr[sortedArrIndex] = arr[i];
    }
    else
    {
        for(i = leftIndex; i <= mid; ++i, ++sortedArrIndex)
            sortedArr[sortedArrIndex] = arr[i];
    }

    for(i = begin; i <= end; ++i)
        arr[i] = sortedArr[i];

    delete[] sortedArr;
}

template <typename T>
void RecursiveMergeSort(T arr[], int begin, int end)
{
    int mid;

    if(begin < end)
    {
        mid = (begin + end) / 2;

        RecursiveMergeSort(arr, begin, mid);
        RecursiveMergeSort(arr, mid + 1, end);

        MergeTwoArr(arr, begin, mid, end);
    }
}

template <typename T>
void MergeSort(T arr[], int n)
{
    RecursiveMergeSort(arr, 0, n - 1);
}

template <typename T>
void Swap(T arr[], int index1, int index2)
{
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

template <typename T>
int SelectPivot(T arr[], int begin, int end)
{
    int samples[3] = {begin, (begin + end) / 2, end};

    if(arr[samples[0]] > arr[samples[1]])
        Swap(samples, 0, 1);

    if(arr[samples[1]] > arr[samples[2]])
        Swap(samples, 1, 2);

    if(arr[samples[0]] > arr[samples[1]])
        Swap(samples, 0, 1);

    return samples[1];
}

template <typename T>
int Partition(T arr[], int begin, int end)
{
    int pivotIndex = SelectPivot(arr, begin, end);
    T pivot = arr[pivotIndex];

    int low = begin + 1;
    int high = end;

    Swap(arr, begin, pivotIndex);

    while(low <= high)
    {
        while(pivot >= arr[low] && low <= end)
            low++;

        while(pivot <= arr[high] && high >= begin + 1)
            high--;

        if(low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, begin, high);
    return high;
}

template <typename T>
void RecursiveQuickSort(T arr[], int begin, int end)
{
    if(begin <= end)
    {
        int pivot = Partition(arr, begin, end);
        RecursiveQuickSort(arr, begin, pivot - 1);
        RecursiveQuickSort(arr, pivot + 1, end);
    }
}

template <typename T>
void QuickSort(T arr[], int n)
{
    RecursiveQuickSort(arr, 0, n - 1);
}

#include "../07-llist-base-queue/LlistBaseQueue.h"
using namespace llqueue;

constexpr int BUCKET_NUM = 10;

void RadixSort(int arr[], int num, int maxLength)
{
    LlQueue<int> buckets[BUCKET_NUM];
    int bucketIndex;
    int position;
    int di;
    int divfac = 1;
    int radix;

    for(position = 0; position < maxLength; ++position)
    {
        for(di = 0; di < num; ++di)
        {
            radix = (arr[di] / divfac) % BUCKET_NUM;

            buckets[radix].Enqueue(arr[di]);
        }

        for(bucketIndex = 0, di = 0; bucketIndex < BUCKET_NUM; ++bucketIndex)
        {
            while(!buckets[bucketIndex].IsEmpty())
                arr[di++] = buckets[bucketIndex].Dequeue();
        }

        divfac *= 10;
    }
}