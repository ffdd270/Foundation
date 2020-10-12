#include <iostream>
#include <chrono>
#include <vector>
#include "../../01-linked-list/LinkedList.h"

using namespace std::chrono;

microseconds TestArrayTraversal(int arraySize)
{
    int value;
    int* test_array = new int[arraySize];

    for(int i = 0; i < arraySize; ++i)
    {
        test_array[i] = i;
    }

    system_clock::time_point start = system_clock::now();
    for(int i = 0; i < arraySize; ++i)
    {
        value = test_array[i];
    }
    system_clock::time_point  end = system_clock::now();
    microseconds ms = duration_cast<microseconds>(end - start);

    delete[] test_array;
    return ms;
}

microseconds TestLinkedListTraversal(int llistSize)
{
    int value;
    LinkedList<int> test_llist;
    Node<int>* test_node;

    for(int i = 0; i < llistSize; ++i)
    {
        test_llist.push_back(i);
    }
    test_node = test_llist.search(0);

    system_clock::time_point start = system_clock::now();
    for(int i = 0; i < llistSize; ++i)
    {
        value = test_node->data;
        test_node = test_node->next;
    }
    system_clock::time_point  end = system_clock::now();
    microseconds ms = duration_cast<microseconds>(end - start);

    return ms;
}

int main()
{
    std::vector<std::vector<microseconds>> array_test_result = {{}, {}, {}, {}};
    std::vector<std::vector<microseconds>> llist_test_result = {{}, {}, {}, {}};
    constexpr int repetitions = 30;
    constexpr int test_case[4] = {1'000, 10'000, 100'000, 1'000'000};

    for(int test_case_index = 0; test_case_index < 4; ++test_case_index)
    {
        for(int repetition_index = 0; repetition_index < repetitions; ++repetition_index)
        {
            array_test_result[test_case_index].push_back(TestArrayTraversal(test_case[test_case_index]));
            llist_test_result[test_case_index].push_back(TestLinkedListTraversal(test_case[test_case_index]));
        }
    }

    std::cout << "Test Repetition : " << repetitions << " time(s)" << std::endl;
    std::cout << "Test Case : ";
    for(int tcase : test_case)  { std::cout << tcase << " | ";}
    std::cout << std::endl << std::endl;

    std::cout << "Average Array Traversal Spending Time : ";
    for(auto& time_pool : array_test_result)
    {
        double sum = 0;
        int size = time_pool.size();

        for(auto time : time_pool)
        {
            sum += time.count();
        }
        sum = sum / size;
        std::cout << sum << ", ";
    }
    std::cout << std::endl;

    std::cout << "Average LList Traversal Spending Time : ";
    for(auto& time_pool : llist_test_result)
    {
        double sum = 0;
        int size = time_pool.size();

        for(auto time : time_pool)
        {
            sum += time.count();
        }
        sum = sum / size;
        std::cout << sum << ", ";
    }
    return 0;
}