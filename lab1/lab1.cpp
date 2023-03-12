#include <iostream>
#include <stdio.h>
#include <conio.h>

int myAtoi(const char* text) {
	int s = 0;
	int i = 0;
	while (text[i] != '\0') {
		if (text[i] >= 0 && text[i] <= 9) {
			s = s * 10 + (text[i] - '0');
		}
		++i;
	}
	return s;
}

int main() {
	char buffer[256];
	FILE* f = fopen("in.txt", "r");
	int sum = 0;
	while (fgets(buffer, 256, f)) {
		sum += myAtoi(buffer);
		//strcpy(buffer, "");
	}
	printf("%d", sum);
	getch();
	return 0;
}