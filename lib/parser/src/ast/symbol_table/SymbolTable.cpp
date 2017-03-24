#include "SymbolTable.h"
#include <iostream>

SymbolTable::SymbolTable()
{
    // Nothing else to do
}

SymbolTable::~SymbolTable()
{
    for(auto& pair : table)
    {
        delete pair.second;
    }
}

Symbol* SymbolTable::get(std::string name)
{
    if(contains(name)) {
        return table[name];
    }
    return nullptr;
}

void SymbolTable::put(std::string name, Symbol* symbol)
{
    if(contains(name)) {
        delete table[name];
    }
    table[name] = symbol;
}

bool SymbolTable::contains(std::string name)
{
    return table.count(name) != 0;
}