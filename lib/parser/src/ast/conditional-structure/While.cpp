#include "While.h"

While::While(Block* block_, Expression* condition_) : 
    ConditionalStructure(block_, condition_)
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