#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "Type.h"

class Symbol
{
public:
    Symbol(std::string name, Type type, int address = 0);
    virtual ~Symbol();

    std::string getName();
    Type getType();
    int getAddress(); // Setter ? How to handle address ?

protected:
    std::string name;
    Type type;
    int address;
};

#endif
