#include "Canvas.h"

int main() {
    int x;

    Canvas c(40, 20);
    c.FillRect(10, 3, 15, 15, 't');
    c.Print();



    std::cin >> x;
    return 0;
}