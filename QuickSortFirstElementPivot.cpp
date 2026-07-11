#include <iostream>
#include <vector>

using namespace std;

int partition(vector <int> &arr, int low, int high)
{
    int pivot = arr[low]; //here the first element is the pivot
    int i = low + 1; 
    int j = high;

    while(true)
    {
        while(i <= high && arr[i] <= pivot) i++; //find an element on the left that is bigger than pivot
        while(arr[j] > pivot && j >= low) j--; //find an element on the right that is smaller than pivot
        if(i < j)   swap(arr[i], arr[j]); //fix the misplaced pair and keep scanning
        else{
            swap(arr[low], arr[j]); // set up the pivot in it's place and stop 
            break;
        }
    }

    return j; //latest position of the pivot
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