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
	std::string GetTip() const override final;
};

class Cunoscut final : public Contact {
private:
	std::string nr_telefon;
public:
	Cunoscut(const std::string& nume, const std::string& nr_telefon) : Contact(nume), nr_telefon(nr_telefon) {}
	const std::string& GetNrTelefon() const;
	std::string GetTip() const override final;
};

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
	std::string GetTip() const override final;
};