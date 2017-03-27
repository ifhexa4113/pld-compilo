#include <iostream>

#include "LValueExpression.h"

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
        std::cerr << "Error: use of unknown symbol " << name << "." << std::endl;
        // TODO global flag error
    }
}

