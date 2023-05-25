#pragma once
#include <string>
#include "ContactType.h"

class Contact {
protected:
	std::string name;
	Contact(const std::string& name) : name(name) {}
public:
	std::string GetNume() const;
	virtual ContactType GetTip() const = 0; 
};