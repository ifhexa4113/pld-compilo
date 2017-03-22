#include "For.h"

For::For(Expression* condition_, Expression* initialization_, Expression* increment_) :
    ConditionalStructure(block_, condition_),
    initialization(initialization_),
    increment(increment_)
{
    // Nothing else to do
}

For::~For()
{
    delete initialization;
    delete increment;
}

int For::walkTree()
{
    return -1;
}