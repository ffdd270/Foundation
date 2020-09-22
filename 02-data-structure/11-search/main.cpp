#include <iostream>
#include "InterpolationSearch.h"

int main()
{
    int arr[] = {1, 3, 5, 6, 7};
    int index;

    index = InterpolationSearch(arr, 0, 4, 2);
    std::cout << index;

    return 0;
}