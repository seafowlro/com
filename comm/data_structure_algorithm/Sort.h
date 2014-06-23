
/*
*       author:  mark
*         date:  2014/06/23
* Illustration:  declaration of sort algorithm.
*/

#pragma once

class CSort
{
public:
    CSort();
    ~CSort();
    int quick_sort(int * arr, int low, int high );
    void SortTest();

private:
    int partition(int * arr, int const low, int const high);

    void exchange(int & a, int & b)
    {
        int temp = a;
        a        = b;
        b        = temp;
    }
    
private:
    static const size_t arrSize = 100000000;
    static int element[arrSize];
};

