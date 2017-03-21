#include "Function.h"

Function::Function(std::vector<Expression*> list_, string name_) :
        Expression(),
        parameters(list_),
        name(name_)

{

}

Function::~Function()
{
    for(auto expression : parameters)
        delete expression;
}

int Function::walkTree()
{

}
