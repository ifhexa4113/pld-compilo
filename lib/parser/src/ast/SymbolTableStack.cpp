#include "SymbolTableStack.h"

bool SymbolTableStack::checkSymbolImmediate(std::string name) const
{
    if(stack[0]->contains(name))
            return true;
    return false;
}

bool SymbolTableStack::checkSymbol(std::string name) const
{
    for(auto it = stack.begin(); it != stack.end(); ++it)
        if( (*it)->contains(name) )
            return true;
    return false;
}

void SymbolTableStack::push(SymbolTable& table)
{
    stack.push_front(&table);
}

void SymbolTableStack::addEntry(std::string name, Declaration* symbol)
{
    stack[0]->put(name, symbol);
}

SymbolTable& SymbolTableStack::pop()
{
    SymbolTable& headTable = *stack[0];
    stack.pop_front();
    return headTable;
}

SymbolTable& SymbolTableStack::peek()
{
    return *(stack[0]);
}

bool SymbolTableStack::isEmpty() const
{
    return stack.empty();
}

Declaration* SymbolTableStack::getSymbol(std::string name)
{
    for(auto it = stack.begin(); it != stack.end(); ++it)
        if( (*it)->contains(name))
            return (*it)->get(name);
    return nullptr;
}