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
        std::cout << "SimpleString constructor #2\n";
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
    // 
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


class FootballPlayer
{
public:
    FootballPlayer(const SimpleString& name)
        : name_{name}, number_{0}
    {
        std::cout << "FootballPlayer constructor #1\n";

    }

    // FootballPlayer(SimpleString&& name)
    //     : name_{std::move(name)}, number_{0}
    // {
    //     std::cout << "FootballPlayer constructor MOVE\n";
    // 
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
};

class Contract
{
public:

    int recoverNumber(int number)
    {
        if(typeid(number) != typeid(int))
        {
            std::cout << "The value found in file isn't a number (might be corrupted)... " << std::endl;
            return -1;
        }else
        {
            return number;
        }    
    }

    SimpleString recoverString(SimpleString string)
    {
        if(typeid(string) != typeid(SimpleString))
        {
            std::cout << "The value found in file isn't a SimpleString (might be corrupted)... " << std::endl;
            return " ";
        }else
        {
            return string;
        }    
    }     

    Contract(int duration, int salary, SimpleString FootballPlayerName, SimpleString TeamName)
        : duration_(duration), salary_(salary), FootballPlayerName_(FootballPlayerName), TeamName_(TeamName),
          FootballPlayerShirtNumber_(0)
    {
        duration_ = recoverNumber(duration);
        salary_ = recoverNumber(salary);
        FootballPlayerName_ = recoverString(FootballPlayerName);
        TeamName_ = recoverString(TeamName);

        std::cout << "Contract constructor #1\n";
    }

    Contract(int&& duration, int&& salary, SimpleString&& FootballPlayerName, SimpleString&& TeamName)
        : duration_(std::move(duration)), salary_(std::move(salary)), FootballPlayerName_(std::move(FootballPlayerName)), TeamName_(std::move(TeamName)),
          FootballPlayerShirtNumber_(0)
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