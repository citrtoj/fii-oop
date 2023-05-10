#pragma once
#include "Contact.h"
#include <vector>

class Agenda {
private:
	std::vector<Contact*> contacte;
public:
	Agenda() {}
	Contact* Cauta(const std::string& nume) const;
	std::vector<Contact*> GetPrieteni() const;
	void Sterge(const std::string& nume);
	void Adauga(Contact* c);
};