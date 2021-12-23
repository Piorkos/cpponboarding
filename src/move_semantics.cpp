#include <iostream>
#include <cstring>

// needed on mac
#include <sys/types.h>
//typedef u_int32_t uint32_t;

class SimpleString
{
public:
    SimpleString() = default;
    SimpleString(const char* simpleString)
    {
        std::cout << "SimpleString constructor #1\n";
        size_ = std::strlen(simpleString);
        data_ = new char[size_];
        memcpy(data_, simpleString, size_);
    }

    SimpleString(const SimpleString& simpleString)
    {
        std::cout << "SimpleString constructor COPY\n";
        size_ = simpleString.size_;
        data_ = new char[size_];
        memcpy(data_, simpleString.data_, size_);
    }

    // SimpleString(SimpleString&& simpleString)
    // {
    //     std::cout << "SimpleString constructor MOVE\n";
    //     size_ = simpleString.size_;
    //     data_ = simpleString.data_;
    
    //     simpleString.size_ = 0;
    //     simpleString.data_ = nullptr;
    // }

    // SimpleString& operator=(SimpleString&& simpleString)
    // {
    //     std::cout << "SimpleString operator= MOVE\n";
    // 
    //     if(this != &simpleString)
    //     {
    //         delete[] data_;
    // 
    //         size_ = simpleString.size_;
    //         data_ = simpleString.data_;
    // 
    //         simpleString.size_ = 0;
    //         simpleString.data_ = nullptr;
    //     }
    // 
    //     return *this;
    // }

    ~SimpleString()
    {
        std::cout << "SimpleString destructor\n";
        delete data_;
        data_ = nullptr;
    }

    void print()
    {
        std::cout << "SimpleString: " << data_ << "\n";
    }

private:
    char* data_;
    uint32_t size_;
};

class Contract
{
public:
    
    Contract(int duration, int salary, SimpleString FootballPlayerName, SimpleString TeamName)
        : duration_(duration), salary_(salary), FootballPlayerName_(FootballPlayerName), TeamName_(TeamName), FootballPlayerShirtNumber_(0)
    {
        std::cout << "Contract constructor #1\n";
    }

    Contract(int duration, int salary, SimpleString& FootballPlayerName, SimpleString& TeamName)
        : duration_(duration), salary_(salary), FootballPlayerName_(FootballPlayerName), TeamName_(TeamName), FootballPlayerShirtNumber_(0)
    {
        std::cout << "Contract constructor COPY #1\n";
    }

    // Contract(int duration, int salary, SimpleString&& FootballPlayerName, SimpleString&& TeamName)
    //     : duration_(duration), salary_(salary), FootballPlayerName_(std::move(FootballPlayerName)), TeamName_(std::move(TeamName)), FootballPlayerShirtNumber_(0)
    // {
    //     std::cout << "Contract constructor MOVE #1\n";
    // }

    Contract(Contract&& contract)
    {
        std::cout << "Contract constructor MOVE\n";
    }

    ~Contract()
    {
        std::cout << "Contract destructor\n";
    }

private:
    int duration_;
    int salary_;
    SimpleString FootballPlayerName_;
    SimpleString TeamName_;
    int FootballPlayerShirtNumber_;

};

class FootballPlayer
{
public:
    FootballPlayer(const SimpleString& name, Contract contract)
        : name_{name}, number_{0} , contract_{std::move(contract)}
    {
        std::cout << "FootballPlayer constructor #1\n";
    }

    // FootballPlayer(SimpleString&& name, Contract&& contract)
    //     : name_{std::move(name)}, number_{0}, contract_{std::move(contract)}
    // {
    //     std::cout << "FootballPlayer constructor MOVE\n";
    
    // }

    ~FootballPlayer()
    {
        std::cout << "FootballPlayer destructor\n";
    }

    void printName()
    {
        std::cout << "FootballPlayer name = ";
        name_.print();
    }

private:
    SimpleString name_;
    int number_;
    Contract contract_;
};

