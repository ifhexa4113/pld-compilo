#include "SymbolTable.h"

SymbolTable::SymbolTable()
{

}

SymbolTable::~SymbolTable()
{
    for(auto& pair : table)
        delete pair.second;
}

Symbol* SymbolTable::get(std::string name)
{
    return table[name];
}

void SymbolTable::put(std::string name,Symbol* symbol)
{
    table[name] = symbol;
}