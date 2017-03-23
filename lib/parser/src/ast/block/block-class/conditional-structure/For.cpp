#include "For.h"

For::For(Block* block_, Expression* condition_, Expression* initialization_, Expression* increment_) :
        ConditionalStructure(block_, condition_),
        initialization(initialization_),
        increment(increment_)
{

}

For::~For()
{
    delete initialization;
    delete increment;
}

int For::walkTree()
{
        
}