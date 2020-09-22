#pragma once
#include <iostream>

int InterpolationSearch(int arr[], int first, int last, int target)
{
    int mid;

    if(arr[first] > target || target > arr[last])
        return -1;

    mid = ( 1.0 * (target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

    if(arr[mid] == target)
        return mid;
    else
        return InterpolationSearch(arr, mid + 1, last, target);
}

