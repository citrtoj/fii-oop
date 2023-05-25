#include "Cunoscut.h"

ContactType Cunoscut::GetTip() const {
	return ContactType::CunoscutType;
}
const std::string& Cunoscut::GetNrTelefon() const {
	return nr_telefon;
}