#include "Map.h"
#include <iostream>
using namespace std;

int main() {
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m) {
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	m.Delete(10);
	for (auto [key, value, index] : m) {
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	Map<int, const char*> m2;
	m2[10] = "C++";
	std::cout << m.Includes(m2);
	m[10] = "C++";
	std::cout << " " << m.Includes(m2);
	m2[12] = "Not a key in m";
	std::cout << " " << m.Includes(m2);
	m2.Clear();
	std::cout << " " << m.Includes(m2);
	return 0;
}
