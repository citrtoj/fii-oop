#include "Prieten.h"

ContactType Prieten::GetTip() const {
	return ContactType::PrietenType;
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