#include <iostream>
#include "Array.h"
#include "CustomExceptions.h"

using namespace std;

int main() {
	Array<int> arr;
	arr += 2;
	arr += 4;
	Array<int> arr2;
	arr2 += 3;
	arr2 += 5;
	arr2 += 7;
	arr.Insert(1, arr2);
	arr.Sort();
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		std::cout << *it << " ";
	}
	try {
		std::cout << arr[arr.Find(20)]; //arr[-1]
	}
	catch (InvalidIndex e) {
		std::cout << e.what();
	}
}