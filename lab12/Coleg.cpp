#include "Coleg.h"

ContactType Coleg::GetTip() const {
	return ContactType::ColegType;
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