#pragma once

#include <vector>
#include <utility>

namespace LastElementQuickSort
{
    inline int partition(std::vector <int> &arr, int low, int high)
    {
        int pivot = arr[low]; //here the first element is the pivot
        int i = low + 1; 
        int j = high;

        while(true)
        {
            while(i <= high && arr[i] <= pivot) i++; //find an element on the left that is bigger than pivot
            while(arr[j] > pivot && j >= low) j--; //find an element on the right that is smaller than pivot
            if(i < j)   std::swap(arr[i], arr[j]); //fix the misplaced pair and keep scanning
            else{
                std::swap(arr[low], arr[j]); // set up the pivot in it's place and stop 
                break;
            }
        }

        return j; //latest position of the pivot
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