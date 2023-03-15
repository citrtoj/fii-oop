#include <iostream>
#include "Sort.h"

#pragma warning(disable:4996)

int main() {
	Sort list(20, 1, 20);
	list.Print();
	list.InsertSort();
	list.Print();
	std::cout << "\n\n";

	Sort list2({ 37, 14, 25, 23, 11, 6, 87, 2323, 121, 22 });
	list2.Print();
	list2.QuickSort();
	list2.Print();
	std::cout << "\n\n";

	char v[] = "10,20,40,5";
	Sort list3(v);
	list3.Print();
	list3.BubbleSort();
	list3.Print();
	std::cout << "\n\n";
}
