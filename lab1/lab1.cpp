#include <iostream>
#include <cstring>
#include <stdio.h>
#include <conio.h>

//ex 2
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
	//ex 2
	char buffer[256];
	FILE* f = fopen("in.txt", "r");
	int sum = 0;
	while (fgets(buffer, 256, f)) {
		sum += myAtoi(buffer);
		strcpy(buffer, "");
	}
	printf("%d\n", sum);

	//ex 3
	char* words[256] = {0}; //vector de pointeri la cuvinte stocate pe heap
	int n = 0;
	if (scanf("%[^\n]s", buffer)) {
		char* p;
		p = strtok(buffer, " ");
		while (p) {
			if (n <= 0) {
				if (words[0] = new char[strlen(p)]) {
					strcpy(words[0], p);
				}
			}
			else {
				int j = n - 1;
				char* element = new char[strlen(p)];
				strcpy(element, p);
				while (j >= 0 && ((strlen(words[j]) < strlen(p)) || ( (strlen(words[j]) == strlen(p) && strcmp(words[j], p) > 0)))) {
					words[j + 1] = words[j];
					--j;
				}
				words[j + 1] = element;
			}
			
			++n;
			p = strtok(NULL, " ");
		}
	}
	else {
		printf("error reading sentence from input!");
	}
	for (int i = 0; i < n; ++i) {
		std::cout << words[i] << " ";
	}

	printf("\nPress any key to exit...");
	std::cin >> n;
	return 0;
}

/*
* ex 4
#include <iostream>
using namespace std;

bool isPrime(int n)
{
	for (int tr = 2; tr < n / tr; tr++)
		if ((n % tr ) == 0)
			return false;
	return true;
}

int main()
{
	int n;
	std::cout << "Enter a number:";
	std::cin >> n;
	if (isPrime(n))
		std::cout << n << " is prime !";
	else
		std::cout << n << " is NOT prime !";
	return 0;
}
*/