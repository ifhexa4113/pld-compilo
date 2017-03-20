#include "ConditionalStructure.h"

ConditionalStructure::ConditionalStructure(Block* block_, Expression* condition_) : 
        BlockClass(block_),
        condition(condition_)
{

}

ConditionalStructure::~ConditionalStructure()
{
        delete condition;
}

int ConditionalStructure::walkTree()
{
        
}