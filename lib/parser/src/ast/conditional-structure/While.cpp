#include "While.h"

While::While(Expression* condition_) :
    ConditionalStructure(condition_)
{
    // Nothing else to do
}

While::~While()
{
    // Nothing else to do
}

int While::walkTree()
{
    return -1;
}