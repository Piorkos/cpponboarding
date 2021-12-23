#include <iostream>
#include <time.h>
#include "src/l_r_values.cpp"
#include "src/move_semantics.cpp"
#include <vector>

int main()
{
    clock_t start, end;
    std::cout << "----start \n";
  
    /* Recording the starting clock tick.*/
    start = clock();
   
    // Recording the end clock tick.
  
    // Calculating total time taken by the program.
    
    // std::cout << "--lvalues and rvalues \n";
    // lrValues();

<<<<<<< HEAD
    //Contract defContract(20,10000,"Alberto", "AlbertoTeam");
    //FootballPlayer diego("Diego", defContract);
    //diego.printName();

    // std::cout << "--std::move and assignment operator \n";
    // SimpleString diego{"Diego"};
    // SimpleString ronaldo{"Ronaldo"};
    // ronaldo = std::move(diego);
 

    //create a vector of contracts
    //for ... 100
    //new contract (param)
    //vector.pushback(contract)
    //delete contract

    //std::cout << "--move semantics \n";
    std::cout << "--copy constructors \n";

    for (size_t i = 0; i < 1000; i++)
    {
        FootballPlayer *fernando = new FootballPlayer("Fernando", Contract(30,1000,"Messi","Madrid"));
        delete fernando;
    }
        
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << std::fixed 
         << time_taken;
    std::cout << " sec " << std::endl;
=======
    std::cout << "--move semantics \n";
    // FootballPlayer diego("Diego");
    // diego.printName();

    SimpleString name{"Diego"};
    SimpleString brother{name};
    name.print();
    brother.print();
>>>>>>> parent of 4f05f00... move assignment operator

    std::cout << "----end\n";


    return 0;
}