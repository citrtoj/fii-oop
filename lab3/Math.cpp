#include "Math.h"

static int Math::Add(int lhs, int rhs) {
	return lhs + rhs;
}

static int Math::Add(int arg1, int arg2, int arg3) {
	return arg1 + arg2 + arg3;
}

static int Math::Add(double lhs, double rhs) {
	return (int)(lhs + rhs);
}

static int Math::Add(double arg1, double arg2, double arg3) {
	return (int)(arg1 + arg2 + arg3);
}

static int Math::Mul(int lhs, int rhs) {
	return lhs * rhs;
}

static int Math::Mult(int arg1, int arg2, int arg3) {
	return arg1 * arg2 * arg3;
}

static int Math::Mul(double lhs, double rhs) {
	return (int)(lhs * rhs);
}

static int Math::Mul(double arg1, double arg2, double arg3) {
	return (int)(arg1 * arg2 * arg3);
}

static int Math::Add(int count, ...) {
	//idk
}

static char* Math::Add(const char* lhs, const char* rhs) {
	//idk
}