#include <iostream>
#include "ArrayExpression.h"
#include "NullExpression.h"

ArrayExpression::ArrayExpression(std::string name_, Expression* index_) :
    LValueExpression(name_),
    index(index_)
{
    if(index == nullptr)
    {
        index = new NullExpression();
    }
}

ArrayExpression::~ArrayExpression()
{
    delete index;
}

int ArrayExpression::walkTree()
{
    std::cout << name << "[" << index->walkTree() << "]";
    return 0;
}

void ArrayExpression::fillSymbolTable(SymbolTableStack& stack)
{
    LValueExpression::fillSymbolTable(stack);
    index->fillSymbolTable(stack);
}

void ArrayExpression::fillAstTrace(std::string& astTrace)
{
    astTrace += "ARRAY EXPR\n";
}