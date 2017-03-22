#include "ConditionalStructure.h"

ConditionalStructure::ConditionalStructure(Expression* condition_) :
    AstNode(),
    condition(condition_)
{
    // Nothing else to do
}

ConditionalStructure::~ConditionalStructure()
{
    delete condition;
}

int ConditionalStructure::walkTree()
{
    return -1;
}