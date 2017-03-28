#include <iostream>

#include "Declaration.h"

Declaration::Declaration(std::string name_, Type type_, int address_) :
    AstNode(),
    name(name_),
    type(type_),
    address(address_)
{
    // Nothing else to do
}

Declaration::~Declaration()
{
    // Nothing else to do
}

std::string Declaration::getName() const
{
    return name;
}

Type Declaration::getType() const
{
    return type;
}

int Declaration::getAddress() const
{
    return address;
}

// void Declaration::fillSymbolTable(SymbolTableStack& stack)
// {
//     if(stack.checkSymbolImmediate(name))
//     {
//         std::cerr << "Error: redeclaration of symbol " << name << "." << std::endl;
//         // TODO error flag
//     }
//     stack.addEntry(name, this);
// }