#include <iostream>

void print(int& toPrint)
{
    std::cout << "lvalue: toPrint = " << toPrint << "\n";
}


void print(int&& toPrint)
{
    std::cout << "rvalue: toPrint = " << toPrint << "\n";
}

void lrValues()
{
    int widht{2};
    int heigth{3};
    int total = widht + heigth;

    print(widht);
    print(heigth);
    print(total);
    print(widht + heigth);
}