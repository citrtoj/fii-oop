#pragma once
#include <iostream>
template <class K, class V>
class Map {
public:
	struct pair {
		K key;
		V value;
		int index;
	}* pairs;

	int size;
	int count;

	Map() : size(2), count(0) {
		pairs = new pair[size];
	}
	~Map(){
		delete[] pairs;
	}
	void Clear() {
		delete[] pairs;
		size = 4;
		pairs = new pair[size];
		count = 0;
	}
	pair* begin() {
		return &pairs[0];
	}
	pair* end() {
		return &pairs[count];
	}
	const pair* begin() const {
		return &pairs[0];
	}
	const pair* end() const {
		return &pairs[count];
	}

	void reserve() {
		while (size < count + 1) {
			size *= 2;
		}
		pair* tmp = new pair[size];
		for (int i = 0; i < count; ++i) {
			tmp[i].key = pairs[i].key;
			tmp[i].value = pairs[i].value;
			tmp[i].index = i;
		}

		delete[] pairs;
		//pairs = nullptr;
		pairs = tmp;
	}
	V& operator[](const K& key) {
		for (int i = 0; i < count; ++i) {
			if (pairs[i].key == key) {
				return pairs[i].value;
			}
		}
		if (count + 1 > size) {
			reserve();
		}
		pairs[count].key = key;
		pairs[count].index = count;
		count++;
		return pairs[count - 1].value;
	}
	void Set(const K& key, const V& value) {
		(*this)[key] = value;
	}
	bool Get(const K& key, V& value) {
		for (int i = 0; i < count; ++i) {
			if (pairs[i].key == key) {
				value = pairs[i].value;
				return true;
			}
		}
		return false;
	}
	int Count() {
		return count;
	}

	bool Delete(const K& key) {
		for (int i = 0; i < count; ++i) {
			if (pairs[i].key == key) {
				for (int j = i; j < count - 1; ++j) {
					pairs[j] = pairs[j + 1];
					pairs[j].index = j;
				}
				pairs[count] = pair();
				--count;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map) {
		V tmpValue = V();
		bool isIncluded = true;
		for (const auto p : map) {
			if (!Get(p.key, tmpValue)) {
				isIncluded = false;
			}
		}
		return isIncluded;
	}
};