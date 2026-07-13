#pragma once

#include <vector>
#include <utility>

namespace LastPivotQuickSort
{
    inline int partition(std::vector <int> &arr, int low, int high)
    {
        std::swap(arr[low], arr[high]);

        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;

        while (true)
        {
            do
            {
                i++;
            } while (arr[i] < pivot);

            do
            {
                j--;
            } while (arr[j] > pivot);

            if (i >= j)
                return j;

            std::swap(arr[i], arr[j]);
        }
    }

    inline void quicksort(std::vector <int> &arr, int low , int high)
    {
        if(low < high)
        {
            int pivotIndex = partition(arr, low, high);

            quicksort(arr, low, pivotIndex);
            quicksort(arr, pivotIndex+1, high);
        }
    }
}