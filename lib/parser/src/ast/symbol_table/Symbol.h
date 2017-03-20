#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

class Symbol
{
public:
    Symbol(std::string name, int address = 0);
    virtual ~Symbol();

    std::string getName();
    int getAddress(); // Setter ? How to handle address ?

protected:
    std::string name;
    int address;
};

#endif
