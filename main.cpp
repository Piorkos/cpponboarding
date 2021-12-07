#include <iostream>
#include "src/l_r_values.cpp"
#include "src/move_semantics.cpp"


int main()
{
    std::cout << "----start \n";

    // std::cout << "--lvalues and rvalues \n";
    // lrValues();

    // std::cout << "--move semantics \n";
    // FootballPlayer diego("Diego");
    // diego.printName();

    // std::cout << "--std::move and assignment operator \n";
    // SimpleString diego{"Diego"};
    // SimpleString ronaldo{"Ronaldo"};
    // ronaldo = std::move(diego);

    std::cout << "----end\n";


    return 0;
}