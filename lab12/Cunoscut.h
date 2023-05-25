#pragma once
#include "Contact.h"

class Cunoscut final : public Contact {
private:
	std::string nr_telefon;
public:
	Cunoscut(const std::string& nume, const std::string& nr_telefon) : Contact(nume), nr_telefon(nr_telefon) {}
	const std::string& GetNrTelefon() const;
	ContactType GetTip() const override final;
};