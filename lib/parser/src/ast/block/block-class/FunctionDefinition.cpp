#include <iostream>

#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(Block* block_, std::string name_) :
    BlockClass(block_),
    name(name_)
{

}

int FunctionDefinition::walkTree()
{
    std::cout << "Entering function definition \"" << name << "\", exploring block." << std::endl;
    block->walkTree();
    return 0;
}