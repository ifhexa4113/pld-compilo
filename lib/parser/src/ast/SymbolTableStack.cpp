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
        if(it->contains(name))
            return true;
    return false;
}

void SymbolTableStack::push(SymbolTable& table)
{
    stack.push_front(table);
}

void SymbolTableStack::addEntry(std::string name, Declaration* symbol)
{
    stack[0].put(name, symbol);
}

SymbolTable& SymbolTableStack::pop()
{
    return stack.pop_front();
}

SymboleTable& SymbolTableStack::peek()
{
    return stack[0];
}

bool SymbolTable::isEmpty() const
{
    return stack.empty();
}

Declaration* SymbolTable::getSymbol(std::string name)
{
    for(auto it = stack.begin(); it != stack.end(); ++it)
        if(it->contains(name))
            return it->get(name);
    return nullptr;
}