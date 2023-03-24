#include "Number.h"

unsigned long long Number::toDecimal() const {
	unsigned long long decimal = 0;
	for (int i = 0; i < GetDigitsCount(); ++i) {
		decimal = decimal * GetBase() + Digit(i);
	}
	return decimal;
}

int Number::Digit(int idx) const {
	if (m_number[idx] >= 'A') {
		return m_number[idx] - 'A' + 10;
	}
	else {
		return m_number[idx] - '0';
	}
}

Number::Number(long long number, int base) : m_base(base), m_length(1), m_number(nullptr) {
	//std::cout << "[calling long long constructor...]\n";
	if (number != 0) {
		long long tmp = number;
		while (tmp >= base) {
			tmp /= base;
			m_length++;
		}
		tmp = number;
		m_number = new char[m_length + 1];
		for (int i = (int)m_length - 1; i >= 0; --i) {
			int mod = tmp % base;
			if (mod >= 0 && mod <= 9) {
				m_number[i] = mod + '0';
			}
			else if (mod >= 10 && mod <= 15) {
				m_number[i] = mod - 10 + 'A';
			}
			tmp /= base;
		}
		m_number[m_length] = '\0';
	}
	else {
		m_number = new char[2];
		m_number[0] = '0';
		m_number[1] = '\0';
		m_length = 1;
	}
}

Number::Number(int number, int base) : Number((long long)number, base) {}

Number::Number(const char* value, int base) : m_base(base), m_length(strlen(value)), m_number(nullptr) {
	//std::cout << "[calling const char constructor...]\n";
	m_number = new char[strlen(value) + 1];
	memcpy(m_number, value, strlen(value) + 1);
	m_number[strlen(value)] = '\0';
}

Number::~Number() {
	delete[] m_number;
}

Number::Number(int number) : Number(number, 10) {}

int Number::operator[](size_t i) const {
	return m_number[i];
}

Number::Number(const Number& cp) : m_base(cp.m_base), m_length(cp.m_length) {
	//std::cout << "[calling copy constructor...]\n";
	m_number = new char[m_length + 1];
	memcpy(m_number, cp.m_number, m_length + 1);
	m_number[m_length] = '\0';
}

Number::Number(Number&& mv) noexcept : m_base(mv.m_base), m_length(mv.m_length) {
	//std::cout << "[calling move constructor...]\n";
	m_number = mv.m_number;
	mv.m_number = nullptr;
	mv.m_base = 0;
	mv.m_length = 0;
}

Number& Number::operator=(Number&& mv) noexcept {
	//std::cout << "[calling move assignment...]\n";
	m_base = mv.m_base;
	m_length = mv.m_length;
	char* tmp = m_number;
	m_number = mv.m_number;
	mv.m_number = tmp;
	return (*this);
}

Number& Number::operator= (int value) {
	(*this) = Number(value, m_base);
	return (*this);
}


Number& Number::operator= (const char* value) {
	if (m_length < strlen(value)) {
		delete[] m_number;
		m_number = new char[strlen(value) + 1];
	}
	memcpy(m_number, value, strlen(value) + 1);
	m_length = strlen(value);
	m_number[m_length] = '\0';
	return (*this);
}

Number& Number::operator+=(const Number& rhs) {
	long long n1 = toDecimal(), n2 = rhs.toDecimal();
	n1 += n2;
	//switchbase tot face un construct si un move deci...
	(*this) = Number(n1, (m_base > rhs.m_base ? m_base : rhs.m_base));
	return (*this);
}

Number& Number::operator-=(const Number& rhs) {
	long long n1 = toDecimal(), n2 = rhs.toDecimal();
	n1 -= n2;
	(*this) = Number(n1, (m_base > rhs.m_base ? m_base : rhs.m_base));
	return (*this);
}

Number operator+(const Number& lhs, const Number& rhs) {
	Number tmp(lhs);
	tmp += rhs;
	return tmp;
}

Number operator-(const Number& lhs, const Number& rhs) {
	Number tmp(lhs);
	tmp -= rhs;
	return tmp;
}

Number& Number::operator--() {
	if (m_length == 1) {
		(*this) = "0";
		return (*this);
	}
	//i'm not using memcpy on overlapping memory
	//and all memcpy is is basically a for loop anyway
	for (int i = 0; i < m_length; ++i) {
		m_number[i] = m_number[i + 1];
	}
	m_length--;
	return (*this);
}

Number& Number::operator--(int) {
	m_number[m_length - 1] = '\0';
	m_length--;
	return (*this);
}

bool Number::operator<(const Number& rhs) const {
	long long n1 = toDecimal(), n2 = rhs.toDecimal();
	return n1 < n2;
}

bool Number::operator<=(const Number& rhs) const {
	long long n1 = toDecimal(), n2 = rhs.toDecimal();
	return n1 < n2;
}

bool Number::operator>(const Number& rhs) const {
	long long n1 = toDecimal(), n2 = rhs.toDecimal();
	return n1 > n2;
}

bool Number::operator>=(const Number& rhs) const {
	long long n1 = toDecimal(), n2 = rhs.toDecimal();
	return n1 >= n2;
}

bool Number::operator==(const Number& rhs) const {
	long long n1 = toDecimal(), n2 = rhs.toDecimal();
	return n1 == n2;
}

void Number::SwitchBase(int newBase) {
	if (newBase == m_base) {
		return;
	}
	if (newBase < 2 || newBase > 16) {
		std::cout << "EXCEPTION: Base must be between 2 and 16";
		throw std::exception();
	}
	long long dec = toDecimal();
	(*this) = Number(dec, newBase);
}

void Number::Print() {
	std::cout << m_number << "\n";
}

int Number::GetDigitsCount() const {
	return (int)m_length;
}

int Number::GetBase() const {
	return m_base;
}