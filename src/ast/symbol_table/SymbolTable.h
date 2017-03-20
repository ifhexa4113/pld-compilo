#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <string>

#include "Symbol.h"

class SymbolTable
{
public:
    SymbolTable();
    ~SymbolTable();

    Symbol* get(std::string name);
    void put(std::string name,Symbol* symbol);

private:
    std::map<std::string,Symbol*> table;

};

#endif
