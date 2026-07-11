#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector <int> & arr, int low, int high)
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
        
        swap(arr[left], arr[right]);
    }
    
}

void quicksort(vector <int> &arr, int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quicksort(arr, low, p);
        quicksort(arr, p + 1, high);
    }
}

int main()
{
    srand(time(0));
    vector <int> arr = {9, 5, 6, 2, 1, 4};
    quicksort(arr, 0, arr.size() - 1);
    for(int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}