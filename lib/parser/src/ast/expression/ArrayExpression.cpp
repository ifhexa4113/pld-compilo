#include "ArrayExpression.h"

ArrayExpression::ArrayExpression(std::string name_, Expression* index_) :
    LValueExpression(name_),
    index(index_)
{

}

ArrayExpression::~ArrayExpression()
{
    delete index;
}

int ArrayExpression::walkTree()
{
    
}