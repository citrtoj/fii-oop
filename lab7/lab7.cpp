float operator"" _Kelvin(unsigned long long a) {
    float value = a - 273.15f;
    return value;
}
float operator"" _Fahrenheit(unsigned long long a) {
    float value = (a - 32) / 1.8f;
    return value;
}

#include <iostream>
#include "Tree.h"
int main()
{
    std::cout << "degrees:\n";
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << a << " " << b << "\n\n\nTREE:\n";

    Tree<int> tree;
    tree.add_node(nullptr, 5);
    tree.add_node(tree.root(), 6);
    tree.add_node(tree.root(), 3);
    tree.add_node(tree.root(), 8);
    //works!
    tree.add_node(tree.find(8), 4);
    tree.add_node(tree.find(8), 1);
    tree.add_node(tree.find(8), -2556);
    std::cout << "data of second child of root: " << (*tree.root())[1]->Data() << "\n";
    std::cout << "data of second child of root, with get_node: " << tree.get_node(tree.root(), 1)->Data() << "\n"; //equivalent to above
    //so, insert works well
    std::cout << "count: " << tree.count(tree.root()) << "\n";
    auto* eight = tree.find(8);
    std::cout << "8's children: \n";
    for (size_t i = 0; i < eight->childrenCount(); ++i) {
        std::cout << (*eight)[i]->Data() << " ";
    }
    eight->Sort();
    std::cout << "\nAfter sorting:\n";
    for (size_t i = 0; i < eight->childrenCount(); ++i) {
        std::cout << (*eight)[i]->Data() << " ";
    }
    eight->deleteChildren();
    std::cout << "\n";
    std::cout << "count, after deleting 8's children: " << tree.count(tree.root()) << "\n";

    
}
