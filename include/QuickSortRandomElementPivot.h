#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

namespace RandomElementQuickSort
{
    inline int partition(std::vector <int> & arr, int low, int high)
    {
        int randomIndex = low + rand() % (high - low) / 2;
        int pivot = arr[randomIndex];

        int left = low - 1;
        int right = high + 1;

        while (true)
        {
            do
            {
                left++;
            } while (arr[left] < pivot);

            do
            {
                right--;
            } while (arr[right] > pivot);
            
            if(left >= right)
            {
                return right;
            }
            
            std::swap(arr[left], arr[right]);
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