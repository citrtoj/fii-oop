#pragma once
#include "CustomExceptions.h"
#include <algorithm>

class Compare
{
public:
	virtual bool CompareElements(void* e1, void* e2) = 0; 
};

template<typename T>
class CompareWithOperator : public Compare {
public:
	bool CompareElements(void* e1, void* e2) override {
		if (*((T*)e1) < *((T*)e2)) {
			return -1;
		}
		else if (*((T*)e1) > *((T*)e2)) {
			return 1;
		}
		return 0;
	}
};

template<typename T>
class ArrayIterator
{
public:
	//Nu stiu

	T** Pointer;

	using iterator = ArrayIterator<T>;
	using iterator_category = std::random_access_iterator_tag;
	using reference = T&;
	using value_type = T;
	using pointer = T*;
	using difference_type = std::ptrdiff_t;

	ArrayIterator() {
		Pointer = nullptr;
	}

	ArrayIterator(T** start) noexcept {
		Pointer = start;
	}

	reference operator*() const noexcept {
		return Pointer[0][0];
	}

	reference operator->() const noexcept {
		return Pointer[0][0];
	}

	iterator& operator++() noexcept {
		++Pointer;
		return *this;
	}

	iterator& operator--() noexcept {
		--Pointer;
		return *this;
	}

	iterator& operator+= (difference_type n) noexcept {
		difference_type m = n;
		if (m >= 0) while (m--) ++(*this);
		else while (m++) --(*this);
		return *this;
	}

	iterator& operator-= (difference_type n) noexcept {
		return *this += -n;
	}

	iterator operator+(difference_type n) const noexcept {
		iterator it = *this;
		it += n;
		return it;
	}

	difference_type operator - (const iterator& b) const noexcept {
		return Pointer - b.Pointer;
	}

	iterator operator - (difference_type n) const noexcept {
		iterator it = *this;
		it -= n;
		return it;
	}

	friend bool operator != (const iterator& lhs, const iterator& rhs) noexcept {
		return lhs.Pointer != rhs.Pointer;
	}

	friend bool operator<(const iterator& a, const iterator& b) {
		return (b - a > 0);
	}

	friend bool operator>(const iterator& a, const iterator& b) {
		return (b < a);
	}

	friend bool operator<=(const iterator& a, const iterator& b) {
		return !(a < b);
	}

	friend bool operator>=(const iterator& a, const iterator& b) {
		return !(b > a);
	}

	friend bool operator==(const iterator& a, const iterator& b) {
		return b.Pointer == a.Pointer;
	}

	reference operator[](difference_type idx) const noexcept {
		return Pointer[idx][0];
	}

};

template<class T>
class Array
{
private:
	// Chiar nu inteleg de ce s-a sugerat in template-ul de la laborator T**
	// Ca i un fel de amalgam dintre std::vector si std::deque, dar in acelasi timp niciuna
	// Si deci mai complicat decat ar fi putut sa fie, cam degeaba
	// Dar m-am conformat

	T** List; // lista cu pointeri la obiecte de tipul T*
	size_t Capacity; // dimensiunea listei de pointeri
	size_t Size; // cate elemente sunt in lista

	void resize(size_t size) { //always sizes to biggest 
		
		if (size > Capacity) {
			size_t newCapacity = Capacity;
			if (newCapacity == 0) {
				newCapacity = 1;
			}
			while (newCapacity < size) {
				newCapacity *= 2;
			}
			T** newPointer = new T* [newCapacity];
			for (size_t i = 0; i < newCapacity; ++i) {
				if (i < Size) {
					newPointer[i] = List[i];
				}
				else {
					newPointer[i] = nullptr;
				}
			}
			Capacity = newCapacity;
			List = newPointer;
		}
	}

public:
	using iterator = ArrayIterator<T>;

	//const getters
	size_t capacity() const {
		return Capacity;
	}
	size_t size() const {
		return Size;
	}

	//constructors, indexing, begin(), end()
	Array() : List(nullptr), Capacity(0), Size(0) {}
	~Array() {
		for (size_t i = 0; i < Capacity; ++i) {
			delete List[i];
		}
		delete[] List;
	}

	Array(int capacity) : Capacity(capacity) {
		List = new T * [capacity];
		for (size_t i = 0; i < capacity; ++i) {
			List[i] = nullptr;
		}
	}

	Array(const Array<T>& otherArray) : List(nullptr), Capacity(0), Size(otherArray.size()) {
		resize(otherArray.size());
		for (size_t i = 0; i < otherArray.size(); ++i) {
			List[i] = new T(*(otherArray.List[i]));
		}
	}

	Array(Array<T>&& otherArray) {
		std::swap(List, otherArray.List);
		std::swap(Size, otherArray.Size);
		std::swap(Capacity, otherArray.Capacity);
	}

	Array<T>& operator = (const Array<T>& otherArray) {
		resize(otherArray.size());
		for (size_t i = 0; i < otherArray.size(); ++i) {
			List[i] = new T(*(otherArray.List[i])); //reconstruiesc elementele practic
		}
	}

	Array<T>& operator = (Array<T>&& otherArray) {
		std::swap(List, otherArray.List);
		std::swap(Size, otherArray.Size);
		std::swap(Capacity, otherArray.Capacity);
	}

	T& operator[] (int index) {
		if (index < 0 || index >= Size) {
			throw InvalidIndex();
		}
		return *(List[0]); //elementul de la pointerul de pe List[0]. Dubla referentiere
	}

	iterator begin() {
		return iterator(List);
	}

	iterator end() {
		return iterator(List + Size);
	}

	const iterator begin() const {
		return iterator(List);
	}

	const iterator end() const {
		return iterator(List + Size);
	}

	//insertion / deletion of elements
	const Array<T>& operator+=(const T& newElem) {
		resize(Size + 1);
		List[Size] = new T(newElem);
		++Size;
		return *(this);
	}

	const Array<T>& Insert(int index, const T& newElem) {
		if (index < 0 || index > Size) {
			throw InvalidIndex();
		}
		resize(Size + 1);
		for (size_t i = Size; i > index; --i) {
			List[i] = List[i - 1];
		}
		List[index] = new T(newElem);
		++Size;
		return *(this);
	}

	const Array<T>& Insert(int index, const Array<T>& otherArray) {
		if (index < 0 || index > Size) {
			throw InvalidIndex();
		}
		auto rhsSize = otherArray.size();
		resize(Size + rhsSize);
		for (size_t i = Size - 1; i >= index; --i) {
			List[i + rhsSize] = List[i];
		}
		for (size_t i = 0; i < rhsSize; ++i) {
			List[i + index] = new T(*(otherArray.List[i]));
		}
		Size += rhsSize;
		return *(this);
	}

	const Array<T>& Delete(int index) {
		if (index < 0 || index > Size) {
			throw InvalidIndex();
		}
		delete List[index];
		for (size_t i = index; i < Size - 1; ++i) {
			List[i] = List[i + 1];
		}
		List[Size] = nullptr;
		Size--;
		return *(this);
	}

	void Sort() {
		std::sort(begin(), end());
	}

	void Sort(int(*compare)(const T&, const T&)) {
		std::sort(begin(), end(), [](const auto a, const auto b) {
			return (compare(a, b) < 0);
			});
	}

	void Sort(Compare* comparator) {
		std::sort(begin(), end(), [comparator](const iterator& a, const iterator& b) {
			return (comparator->CompareElements(&a, &b) == 0);
			});
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& x) {  // cauta un element folosind binary search in Array
		size_t b = 0, e = Size - 1;
		while (b < e) {
			auto m = b + (e - b) / 2;
			if (*(begin() + e) == x) {
				return m;
			}
			if (*(begin() + e) < x) {
				e = m + 1;
			}
			else {
				e = m - 1;
			}
		}
		return -1;
	}

	int BinarySearch(const T& x, int(*compare)(const T&, const T&)) {
		size_t b = 0, e = Size - 1;
		while (b < e) {
			auto m = b + (e - b) / 2;
			if (compare(*(begin() + e), x) == 0) {
				return m;
			}
			if (compare(*(begin() + e), x) < 0) {
				b = m + 1;
			}
			else {
				e = m - 1;
			}
		}
		return -1;
	}

	int BinarySearch(const T& x, Compare* comparator) {
		size_t b = 0, e = Size - 1;
		while (b < e) {
			auto m = b + (e - b) / 2;
			if (comparator->CompareElements(*(begin() + e), x) == 0) {
				return m;
			}
			if (comparator->CompareElements(*(begin() + e), x) < 0) {
				b = m + 1;
			}
			else {
				e = m - 1;
			}
		}
		return -1;
	}


	int Find(const T& elem) {
		auto it = std::find(begin(), end(), elem);
		if (it != end()) {
			return static_cast<int>(it - begin());
		}
		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		auto it = std::find(begin(), end(), [compare](auto a, auto b) {
			return compare(a, b) == 0; //fiindca compareu asta poate sa returneze mai multe valori
			});
		if (it != end()) {
			return static_cast<int>(it - begin());
		}
		return -1;
	}

	int Find(const T& elem, Compare* comparator) {
		auto it = std::find(begin(), end(), [comparator](auto a, auto b) {
			return comparator->CompareElements(a, b) == 0; //fiindca compareu asta poate sa returneze mai multe valori
			});
		if (it != end()) {
			return static_cast<int>(it - begin());
		}
		return -1;
	}
};