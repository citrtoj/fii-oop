#include "Math.h"

int Math::Add(int lhs, int rhs) {
	return lhs + rhs;
}

int Math::Add(int arg1, int arg2, int arg3) {
	return arg1 + arg2 + arg3;
}

int Math::Add(double lhs, double rhs) {
	return (int)(lhs + rhs);
}

int Math::Add(double arg1, double arg2, double arg3) {
	return (int)(arg1 + arg2 + arg3);
}

int Math::Mul(int lhs, int rhs) {
	return lhs * rhs;
}

int Math::Mul(int arg1, int arg2, int arg3) {
	return arg1 * arg2 * arg3;
}

int Math::Mul(double lhs, double rhs) {
	return (int)(lhs * rhs);
}

int Math::Mul(double arg1, double arg2, double arg3) {
	return (int)(arg1 * arg2 * arg3);
}

int Math::Add(int count, ...) {
	int sum = 0;
	va_list args;
	va_start (args, count);
	for (int i = 0; i < count; ++i) {
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* lhs, const char* rhs) {
	if (lhs == nullptr || rhs == nullptr) {
		return nullptr;
	}
	const auto fullLen = strlen(lhs) + strlen(rhs) + 2;
	const auto result = new char[fullLen];

	strcpy_s(result, fullLen, lhs);
	strcat_s(result, fullLen, lhs);
	return result;
}