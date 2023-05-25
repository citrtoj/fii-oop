#pragma once
#include "Contact.h"

class Prieten final : public Contact {
private:
	std::string adresa;
	std::string data_nastere;
	std::string nr_telefon;
public:
	Prieten(const std::string& nume, const std::string& data_nastere, const std::string& adresa, const std::string& nr_telefon) : Contact(nume),
		data_nastere(data_nastere), adresa(adresa), nr_telefon(nr_telefon) {}
	const std::string& GetAdresa() const;
	const std::string& GetDataNastere() const;
	const std::string& GetNrTelefon() const;
	ContactType GetTip() const override final;
};