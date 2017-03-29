#include <iostream>

#include "LValueExpression.h"
#include "ast/declaration/Declaration.h"

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

Type LValueExpression::getType(SymbolTableStack& stack)
{
    return (stack.getSymbol(name))->getType();
}

void LValueExpression::fillSymbolTable(SymbolTableStack& stack)
{
    if(!stack.checkSymbol(name))
    {
        std::cerr << "Error: use of unknown symbol " << name << "." << std::endl;
        // TODO global flag error
    }
}

