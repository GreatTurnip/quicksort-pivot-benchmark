#pragma once

#include <vector>
#include <utility>

namespace LastPivotQuickSort
{
    inline int partition(std::vector <int> &arr, int low, int high)
    {
        int pivot = arr[high]; //here the last element is the pivot
        int i = low - 1; 

        for(int j = low; j < high; j++)
        {
            if(arr[j] <= pivot)
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);

        return i + 1;
    }

    inline void quicksort(std::vector <int> &arr, int low , int high)
    {
        if(low < high)
        {
            int pivotIndex = partition(arr, low, high);

            quicksort(arr, low, pivotIndex -1);
            quicksort(arr, pivotIndex+1, high);
        }
    }
}