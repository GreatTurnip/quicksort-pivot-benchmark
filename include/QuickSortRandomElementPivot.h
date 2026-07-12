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
        std::swap(arr[low], arr[randomIndex]);
        int pivot = arr[low];

        int i = low + 1;
        int j = high;

        while (true)
        {
            while(i <= high && arr[i] <= pivot) i++;
            while(arr[j] > pivot)   j--;

            if(i < j)
                std::swap(arr[i], arr[j]);
            else
                break;
        }

        std::swap(arr[low],arr[j]);
        return j;
        
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