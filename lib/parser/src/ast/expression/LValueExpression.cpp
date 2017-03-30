#include <iostream>

#include "LValueExpression.h"
#include "ast/ErrorManager.h"

LValueExpression::LValueExpression(std::string name_) :
    Expression(),
    name(name_)
{
    // Nothing else to do
}

LValueExpression::~LValueExpression()
{
    // Nothing else to do
}

int LValueExpression::walkTree()
{
    return 0;
}

std::string LValueExpression::getName()
{
    return name;
}

void LValueExpression::fillSymbolTable(SymbolTableStack& stack)
{
    if(!stack.checkSymbol(name))
    {
		ErrorManager& errorManager = ErrorManager::getInstance();
		errorManager.addEncounteredError(ErrorManager::UNKNOWN_LVALUE_SYMBOL, name);
    }
}

