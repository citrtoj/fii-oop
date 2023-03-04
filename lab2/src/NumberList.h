#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include <iostream>

class NumberList {
    int numbers[10];
    int count;
public:
    void Init();          // count will be 0
    bool Add(int x);      // adds X to the numbers list and increase the data member count.
                          // if count is bigger or equal to 10, the function will return false
    void Sort();          // will sort the numbers vector
    void Print();         // will print the current vector

};

#endif // NUMBERLIST_H
