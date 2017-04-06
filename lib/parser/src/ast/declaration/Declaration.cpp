#include <iostream>

#include "Declaration.h"
#include "ast/ErrorManager.h"

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

void Declaration::fillSymbolTable(SymbolTableStack& stack)
{
    if(stack.checkSymbolImmediate(name))
    {
		ErrorManager& errorManager = ErrorManager::getInstance();
		errorManager.addEncounteredError(ErrorManager::SYMBOL_REDECLARATION, name);
    }
    stack.addEntry(name, this);
}

bool Declaration::checkNonVoidType(SymbolTableStack&)
{
    if (type == Type::VOID_T)
        return false;
    return true;
}

