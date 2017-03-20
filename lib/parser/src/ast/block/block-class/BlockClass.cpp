#include "BlockClass.h"

BlockClass::BlockClass(Block* block_) : 
        AstNode(),
        block(block_)
{

}

BlockClass::~BlockClass()
{
        delete block;
}

int BlockClass::walkTree()
{

}