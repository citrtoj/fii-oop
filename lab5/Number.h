#pragma once
#include <iostream>
#include <cstring>

class Number //Stringuri cu numere nonnegative in diverse baze
{
	short m_base;
	size_t m_length;
	char* m_number;
	unsigned long long toDecimal() const;
	int Digit(int idx) const;

	Number(long long number, int base);
	Number(int number, int base);

public:

	Number(const char* value, int base); //done
	~Number(); //done
	Number(int number); //done
	Number(const Number& number); //done
	Number(Number&& mv) noexcept; //done

	int operator[](size_t index) const; //done

	Number& operator=(Number&& mv) noexcept; //done
	Number& operator= (int value); //done
	Number& operator= (const char* value); //done

	Number& operator+= (const Number& number); //done
	Number& operator-= (const Number& number); //done

	friend Number operator+(const Number& lhs, const Number& rhs); //done
	friend Number operator-(const Number& lhs, const Number& rhs); //done

	Number& operator--(); //done
	Number& operator--(int); //done

	bool operator<(const Number& rhs) const; //done
	bool operator<=(const Number& rhs) const; //done
	bool operator>(const Number& rhs) const; //done
	bool operator>=(const Number& rhs) const; //done
	bool operator==(const Number& rhs) const; //done

	void SwitchBase(int newBase); //done
	void Print(); //done
	int  GetDigitsCount() const; // done
	int  GetBase() const; // done
};