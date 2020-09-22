#pragma once
#include <iostream>

namespace recursion
{
    [[nodiscard]] inline int BSearchRecur(int arr[], int first, int last, int target)
    {
        const int mid = (first + last) / 2;

        if (first > last)
            return -1;
        else if (arr[mid] == target)
            return  mid;
        else if (target > arr[mid])
            return BSearchRecur(arr, first, mid - 1, target);
        else
            return BSearchRecur(arr, mid + 1, last, target);
    }

    inline void HanoiTowerMove(int num, char from, char by, char to)
    {
        if (num == 1)
            std::cout << "원반 1을 " << from << "에서 " << to << "로 이동.\n";
        else
        {
            HanoiTowerMove(num - 1, from, to, by);
            std::cout << "원반 " << num << "을 " << from << "에서 " << to << "로 이동.\n";
            HanoiTowerMove(num - 1, by, from, to);
        }
    }
}