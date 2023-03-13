#pragma once

#include <initializer_list>
#include <cstdlib>
#include <iostream>
#include <cstring>

class Sort {
private:
    int* m_arr;
    size_t m_count;

    int MyAtoi(const char* text);
    int Partition(int, int, bool);
    void QuickSortUtil(int, int, bool);

public:
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> init_list);
    Sort(int vector[], int count);
    Sort(const char* text);
    Sort(...);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    
    //optional :)
    int  operator[] (size_t index) const;
    
    int  GetElementFromIndex(int index) const;
};
