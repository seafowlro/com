/*
*       author:  mark
*         date:  2014/06/23
* Illustration:  Implementation of sort algorithm.
*/

#include "stdafx.h"
#include "Sort.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int CSort::element[arrSize];

CSort::CSort()
{
}


CSort::~CSort()
{
}


//low: the index of first element;
//high: the index of last element;
int CSort::quick_sort( int * arr, int low, int high )
{
    if ( low < high )
    {
        int pivot = partition(arr, low, high);    //critical: can not use size_t: when pivot == 0, the size_t(-1) is dangerous;

        //test code
        //cout << "partition: " << pivot << "  low: " << low << " high: " << high << endl;

        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }

    return 0;
}


//this method used by the quick sort;
int CSort::partition(int * arr, const int low, const int high)
{
    int refPoint = arr[high];

    int i = low - 1;    //"i" : index of the last element of small range;
    for ( int j = low; j < high; ++j )
    {
        if ( arr[j] < refPoint )        //if arr[j] == refPoint, no need to exchange;
        {
            ++i;        //add one element to the small range; NOW: "i": point to the first element of bigger part, "j": current index;
            exchange( arr[i], arr[j] );
        }
    }

    //exchange the refPoint;
    exchange( arr[i+1], arr[high] );

    return i + 1;
}


void CSort::SortTest()
{
    srand(static_cast<unsigned int>(time(NULL)));
    
    size_t i = 0;
    cout << endl <<"start to generate rand number..." << endl;
    for (; i < arrSize; ++i)
    {
        element[i] = rand();
    }

    cout << "start to quick sort..." << endl;

    clock_t start = clock();
    cout << start << endl;
    quick_sort( element, 0, arrSize - 1);
    clock_t end = clock();
    cout << end << endl;
    cout << "quick_sort " << arrSize << " elements, elapsed " << end - start << " ticks "\
        << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds." << endl;

    cout << "after sort, output:" << endl;
    int count = 0, line = 1;
    bool err = false;
    for (int i = 0; i < arrSize; ++i)
    {
        if (i < 88 )
        {
            cout.width(8);
            cout << std::right << element[i];
            ++count;
        }
        else
        {
            if (element[i-1] > element[i])
            {
                err = true;
            }
        }

        if ( 10 == count  )
        {
            cout << "    " << line << endl;
            ++line;
            count = 0;
        }
    }

    if ( err )
    {
        cout << endl << "sort is wrong..." << endl;
    } 
    else
    {
        cout << endl << "sort is correct..." << endl;
    }

    cout << endl;
}
