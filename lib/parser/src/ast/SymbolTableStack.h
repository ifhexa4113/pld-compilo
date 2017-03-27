#ifndef SYMBOL_TABLE_STACK_H
#define SYMBOL_TABLE_STACK_H

#include <deque>
#include <string>

#include "SymbolTable.h"
#include "declaration/Declaration.h"

class SymbolTableStack
{

public:
    bool checkSymbolImmediate(std::string name) const;
    bool checkSymbol(std::string name) const;
    void push(SymbolTable& table);
    void addEntry(std::string name, Declaration* symbol);
    SymbolTable& pop();
    SymbolTable& peek();
    bool isEmpty() const;
    Declaration* getSymbol(std::string name);


protected:
    std::deque<SymbolTable&> stack;

};


#endif