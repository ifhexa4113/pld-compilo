#include "Parenthesis.h"

Parenthesis::Parenthesis(Expression* expression_) :
    Expression(),
    expression(expression_)
{

}

Parenthesis::~Parenthesis()
{
    delete expression;
}

int Parenthesis::walkTree()
{
    
}
