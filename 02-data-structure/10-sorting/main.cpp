#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include "Sorting.h"

constexpr int ARR_LEN = 20;
typedef int TEST_TYPE;

int main()
{
    TEST_TYPE array[ARR_LEN];
    for(TEST_TYPE i = 0; i < ARR_LEN - 4; ++i)  // array init
    {
        array[i] = i;
    }
    array[ARR_LEN - 4] = 0;                     // 처음 요소 중복 체크
    array[ARR_LEN - 3] = (ARR_LEN - 4) / 2;     // 중간 요소 중복 체크
    array[ARR_LEN - 2] = (ARR_LEN - 4) / 2;     // 중간 요소 중복 체크
    array[ARR_LEN - 1] = ARR_LEN - 5;           // 마지막 요소 중복 체크

    std::vector<void (*)(TEST_TYPE[] , int)> sorting_func = {BubbleSort, SelectionSort, InsertionSort, HeapSort, MergeSort, QuickSort};

    for(auto func : sorting_func)
    {
        std::cout << "Algorithm Starts!\n";

        std::random_device rd;
        std::mt19937 g(rd());

        std::shuffle(std::begin(array), std::end(array), g);    // shuffle array

        std::cout << "Before : ";
        for(auto elem : array)
            std::cout << elem << " ";           // show shuffled array
        std::cout << std::endl;

        func(array, ARR_LEN);                   // apply sorting algorithm

        std::cout << "After  : ";
        for(auto elem : array)
            std::cout << elem << " ";           // show sorted array

        std::cout << "\nAlgorithm Ended!\n\n";
    }


    std::cout << "Algorithm Starts!\n";

    int radixTestArray[7] = {13, 212, 14, 7147, 10987, 7, 15};
    int length = 7;

    std::cout << "Before : ";
    for(auto elem : radixTestArray)
        std::cout << elem << " ";
    std::cout << std::endl;

    RadixSort(radixTestArray, length, 5);

    std::cout << "After  : ";
    for(auto elem : radixTestArray)
        std::cout << elem << " ";

    std::cout << "\nAlgorithm Ended!\n\n";
    return 0;
}