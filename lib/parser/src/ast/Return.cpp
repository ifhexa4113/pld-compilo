#include "Return.h"

Return::Return(Expression* value_) :
    AstNode(),
    value(value_)
{

}

Return::~Return()
{
    delete value;
}

int Return::walkTree()
{

}