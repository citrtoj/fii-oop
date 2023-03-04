#include "NumberList.h"

void NumberList::Init() {
    count = 0;
}

bool NumberList::Add(int x) {
    if (count >= 10) {
        return 0;
    }
    numbers[count] = x;
    count++;
}

void NumberList::Sort() {
    //selection sort ca fac doar swapuri
    for (int i = count - 1; i > 0; --i) {
        int maxim = numbers[i], poz = i;
        for (int j = i - 1; j >= 0; --j) {
            if (numbers[j] > maxim) {
                maxim = numbers[j];
                poz = j;
            }
        }
        if (poz != i) {
            numbers[poz] = numbers[i];
            numbers[i] = maxim;
        }
    }
}

void NumberList::Print() {
    for (int i = 0; i < count; ++i) {
        std::cout<<numbers[i]<<" ";
    }
}
