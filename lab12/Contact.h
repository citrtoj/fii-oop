#pragma once
#include <string>

class Contact {
protected:
	std::string name;
	Contact(const std::string& name) : name(name) {}
	//nu vom avea contact default, deci nu va fi construibil din afara
public:
	std::string GetNume() const;
	virtual std::string GetTip() const = 0; 
};