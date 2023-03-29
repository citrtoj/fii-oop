#include "Header.h"
#pragma warning(disable: 4996)
int main() {
    A* instancePointer = A::GetInstance();
    instancePointer->ChangePath("Fisier.txt");
    instancePointer->Write("scriem\n\n\n");

    Derivat d; //ctor Baza; ctor Derivat
    d.Calcul();
    int result = d.Get();
    char array[10] = { 0 };
    sprintf(array, "%d\n", result);
    A::GetInstance()->Write(array); //80

    Baza* bazaPointer = new Derivat(); //ctor Baza, ctor Derivat
    bazaPointer->Calcul(); //foloseste Baza::a
    int result2 = bazaPointer->Get();
    sprintf(array, "%d\n", result2);
    A::GetInstance()->Write(array); //24

    delete bazaPointer; //dtor baza

    //instancePointer->DestroyInstance();

}
//dtor Derivat; dtor Baza;