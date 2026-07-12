#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <cstdlib>

// my own headers

#include "../include/QuickSortFirstElementPivot.h"
#include "../include/QuickSortLastElementPivot.h"
#include "../include/QuickSortMiddleElementPivot.h"
#include "../include/QuickSortRandomElementPivot.h"
#include "../include/timer.h"

using namespace std;

int MIN_SIZE = 10;
int MAX_SIZE = 5000;
int STEP = 10;
int REPETIOTIONS = 20;

//random array generator

vector <int> randomArray(int n)
{
    vector <int> arr(n);
    for(int i = 0; i < n; i++)  arr[i] = rand() % 1'000'000 + 1;
    return arr;
}

//generate ascending array

vector <int> ascendingArray(int n)
{
    vector <int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i;
    return arr;
}

//generate descending array

vector <int> descendingArray(int n)
{
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  arr[i] = n - i;
    return arr;
}

//run experiment function

void experiment(const string &arrayType, vector<int> (*generator)(int), const string &ouputFile)
{
    ofstream out(ouputFile);
    out << "size,First,Last,Middle,Random\n";

    cout << "RUNNING EXPERIMENT :" <<arrayType <<endl;

    for(int n = MIN_SIZE; n <= MAX_SIZE; n += STEP)
    {
        double totalFirst = 0, totalLast = 0, totalMiddle = 0, totalRandom = 0;
        for(int rep = 0; rep < REPETIOTIONS; rep++)
        {
            vector <int> base = generator(n); //this is the main copy

            vector <int> a = base;
            totalFirst += executionTimeCounter(
                [&]()
                {
                    FirstPivotQuickSort::quicksort(a, 0, (int)a.size() - 1);
                }
            );
            totalLast += executionTimeCounter(
                [&]()
                {
                    LastPivotQuickSort::quicksort(a, 0, (int)a.size() - 1);
                }
            );
            totalMiddle += executionTimeCounter(
                [&]()
                {
                    MiddlePivotQuickSort::quicksort(a, 0, (int)a.size() - 1);
                }
            );
            totalRandom += executionTimeCounter(
                [&]()
                {
                    RandomPivotQuickSort::quicksort(a, 0, (int)a.size() - 1);
                }
            );
        }

        out << n << ","
        << (totalFirst / REPETIOTIONS) << ","
        << (totalLast / REPETIOTIONS) << ","
        << (totalMiddle / REPETIOTIONS) << ","
        << (totalRandom / REPETIOTIONS) << endl;

        if(n % 1000 == 0)   cout << " SIZE " << n << " DONE" << endl;
    }

    out.close();
    cout << "FINISHED AND SAVED AS: " << ouputFile << endl;
}

int main()
{
    srand(time(0));

    experiment("Random", randomArray, "random.csv");
    experiment("Ascending", ascendingArray, "ascending_results.csv");
    experiment("Descending", descendingArray, "descending_results.csv");

    cout << "EVERYTHING IS FINISHED" <<endl;
    return 0;
}