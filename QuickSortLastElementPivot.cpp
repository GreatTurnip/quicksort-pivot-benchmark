#include <iostream>
#include <vector>

using namespace std;

int partition(vector <int> &arr, int low, int high)
{
    int pivot = arr[high]; //here the last element is the pivot
    int i = low - 1; 

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quicksort(vector <int> &arr, int low , int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex -1);
        quicksort(arr, pivotIndex+1, high);
    }
}

int main()
{
    vector <int> arr = {50, 70, 60, 90, 40, 80, 10, 20, 30};
    quicksort(arr, 0, arr.size() -1);
    cout << "Sorted Array: ";
    for(int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}