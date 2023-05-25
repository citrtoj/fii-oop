#pragma once
#include "Contact.h"

class Coleg final : public Contact {
private:
	std::string serviciu;
	std::string adresa;
	std::string nr_telefon;
public:
	Coleg(const std::string& nume, const std::string& serviciu, const std::string& adresa, const std::string& nr_telefon) : Contact(nume),
		serviciu(serviciu), adresa(adresa), nr_telefon(nr_telefon) {}
	const std::string& GetServiciu() const;
	const std::string& GetAdresa() const;
	const std::string& GetNrTelefon() const;
	ContactType GetTip() const override final;
};