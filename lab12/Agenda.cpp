#include "Agenda.h"

std::vector<Contact*> Agenda::GetPrieteni() const {
	std::vector<Contact*> prieteni;
	for (auto c : contacte) {
		if (c->GetTip() == ContactType::PrietenType) {
			prieteni.push_back(c);
		}
	}
	return prieteni;
}

Contact* Agenda::Cauta(const std::string& nume) const {
	for (auto c : contacte) {
		if (c->GetNume() == nume) {
			return c;
		}
	}
	return nullptr;
}

void Agenda::Sterge(const std::string& nume) {
	auto tmp = std::find_if(contacte.begin(), contacte.end(), [nume](Contact* c) -> bool {
		return c->GetNume() == nume;
		});
	contacte.erase(tmp);
}

void Agenda::Adauga(Contact* c) {
	contacte.push_back(c);
}