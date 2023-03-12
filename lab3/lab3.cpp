#include "Canvas.h"

int main() {
    int x;

    Canvas c(40, 20);
    c.FillRect(10, 3, 15, 15, 't');
    c.DrawLine(10, 10, 19, 13, 't');
    c.DrawCircle(20, 10, 8, 'a');
    c.Print();


    std::cin >> x;
    return 0;
}