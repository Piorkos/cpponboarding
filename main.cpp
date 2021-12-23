#include <iostream>
#include <time.h>
#include "src/l_r_values.cpp"
#include "src/move_semantics.cpp"


int main()
{
    clock_t start, end;
    std::cout << "----start \n";
  
    /* Recording the starting clock tick.*/
    start = clock();
   
  
    // Calculating total time taken by the program.
    
    // std::cout << "--lvalues and rvalues \n";
    // lrValues();

    std::cout << "--move semantics \n";
    FootballPlayer diego("Diego");
    diego.printName();

    // std::cout << "--std::move and assignment operator \n";
    // SimpleString diego{"Diego"};
    // SimpleString ronaldo{"Ronaldo"};
    // ronaldo = std::move(diego);

    // Recording the end clock tick.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed 
         << time_taken;
    std::cout << " sec " << std::endl;




    std::cout << "----end\n";


    return 0;
}