#include "ContactTypes.h"

std::string Prieten::GetTip() const {
	return std::string("Prieten");
}
const std::string& Prieten::GetAdresa() const {
	return adresa;
}
const std::string& Prieten::GetDataNastere() const {
	return data_nastere;
}
const std::string& Prieten::GetNrTelefon() const {
	return nr_telefon;
}

std::string Cunoscut::GetTip() const {
	return std::string("Cunoscut");
}
const std::string& Cunoscut::GetNrTelefon() const {
	return nr_telefon;
}

std::string Coleg::GetTip() const {
	return std::string("Coleg");
}
const std::string& Coleg::GetAdresa() const {
	return adresa;
}
const std::string& Coleg::GetServiciu() const {
	return serviciu;
}
const std::string& Coleg::GetNrTelefon() const {
	return nr_telefon;
}