#include <iostream>

#include "Return.h"

Return::Return(Expression* value_) :
    AstNode(),
    value(value_)
{

}

Return::~Return()
{
    if(value != nullptr)
        delete value;
}

int Return::walkTree()
{
    std::cout << "Return node" << std::endl;
    return 0;
}