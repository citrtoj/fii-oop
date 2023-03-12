#include <iostream>
#include <cstring>
#include <stdio.h>
#include <conio.h>

int myAtoi(const char* text) {
	int s = 0;
	int i = 0;
	while (text[i] != '\0') {
		if (text[i] >= '0' && text[i] <=  '9') {
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
		strcpy(buffer, "");
	}
	printf("%d", sum);

	//ex 3
	//char** words = new char* [256]();
	if (scanf("%s", buffer)) {
		char* p;
		int n = 0;
		p = strtok(buffer, " ");
		while (p) {
			//TODO
		}
	}
	else {
		printf("error reading sentence from input!");
	}

	return 0;
}