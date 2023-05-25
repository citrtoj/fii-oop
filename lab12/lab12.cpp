#include <iostream>
#include "Agenda.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include "Prieten.h"

int main() {
    Agenda a;
    Prieten* Toma = new Prieten("Toma", "20 aprilie", "Str Principala 60, Adjud, Vrancea", "0798989898");
    Cunoscut* Tim = new Cunoscut( "Tim", "0734343434");
    Prieten* Marian = new Prieten( "Marian", "16 august", "pe Anglea", "0700000000");
    a.Adauga(Tim);
    a.Adauga(Marian);
    a.Adauga(Toma);
    for (Contact* prieten : a.GetPrieteni()) {
        std::cout << (dynamic_cast<Prieten*>(prieten))->GetAdresa() << "\n";
    }
}