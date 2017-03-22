#include "If.h"

If::If(Expression* condition_) :
    ConditionalStructure(condition_)
{
    // Nothing else to do
}

If::~If()
{
    // Nothing else to do
}

int If::walkTree()
{
    return -1;
}