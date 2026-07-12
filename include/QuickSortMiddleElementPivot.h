#pragma once

#include <vector>
#include <utility>

namespace MiddlePivotQuickSort
{
    inline int partition(std::vector <int> & arr, int low, int high)
    {
        int midIndex = low + (high - low) / 2;
        std::swap(arr[low], arr[midIndex]);
        int pivot = arr[low];

        int i = low - 1;
        int j = high + 1;

        while (true)
        {
            do{
                i++;
            }while (arr[i] < pivot);
            do
            {
                j--;
            } while (arr[j] > pivot);
            if( i >= j)
                return j;
            
            std::swap(arr[i], arr[j]);
        }

    }

    inline void quicksort(std::vector <int> &arr, int low, int high)
    {
        if(low < high)
        {
            int p = partition(arr, low, high);
            quicksort(arr, low, p);
            quicksort(arr, p + 1, high);
        }
    }

}