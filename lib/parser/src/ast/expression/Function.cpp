#include "Function.h"

Function::Function(std::vector<Expression*> list, string name_) :
        Expression(),
        parameters(list),
        name(name_)

{

}
Function::~Function()
{
    for(auto expression : list)
        delete expression;
}
int Function::walkTree()
{

}
