#include "SymbolTable.h"

SymbolTable::SymbolTable()
{

}

SymbolTable::~SymbolTable()
{
    for(auto key : table)
        delete table[key];
}

Symbole* SymbolTable::get(std::string name)
{
    return table[name];
}

void SymbolTable::put(std::string name,Symbol* symbol)
{
    table[name] = symbol;
}