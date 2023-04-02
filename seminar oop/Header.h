#pragma once
#include <string>
#include <algorithm>
#include <iostream>

class Test {
public:
	Test() {}
	~Test() {
		std::cout << "calling dtor\n";
	};
};


/*class A {
private:
	A();
	~A();
	static A* instance;
	std::string path;
public:
	static A* GetInstance();
	static void DestroyInstance();
	void Write(std::string mesaj);
	void ChangePath(std::string newPath);
};

class Baza {
	int a;
public:
	Baza();
	virtual ~Baza();
	void Calcul();
	int Get();
};

class Derivat : public Baza {
	int a;
public:
	Derivat();
	~Derivat();
	void Calcul();
	int Get();
};*/