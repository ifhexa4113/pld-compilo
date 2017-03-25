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

Declaration* SymbolTable::get(std::string name)
{
    if(contains(name)) {
        return table[name];
    }
    return nullptr;
}

void SymbolTable::put(std::string name, Declaration* symbol)
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