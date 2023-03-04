#include "NumberList.h"
#include "Student.h"
#include "Globals.h"

int main()
{
    std::cout << "NumberList\n";
    NumberList lista;
    lista.Init();
    lista.Add(5);
    lista.Add(6);
    lista.Add(3);
    lista.Add(26);
    std::cout << "Unsorted: ";
    lista.Print();
    std::cout << "\n";
    lista.Sort();
    std::cout << "Sorted:   ";
    lista.Print();
    std::cout << "\n\n\n";

    std::cout << "Student\n";
    Student Maria;
    Maria.SetName("Maria");
    Maria.SetGradeMath(7.0);
    std::cout << "Average: " << Maria.AverageGrade() << ", for " << Maria.Name() << "\n";

    Student Ion;
    Ion.SetName("Ion");
    Ion.SetGradeMath(10.0);
    std::cout << CompareName(Maria, Ion) << " <- name compare; average compare -> " << CompareAverage(Maria, Ion);
    return 0;
}
