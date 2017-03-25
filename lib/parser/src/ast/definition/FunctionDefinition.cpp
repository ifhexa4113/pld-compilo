#include <iostream>
#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(std::string name_) :
    Definition(name_),
    Block()
{
    // Nothing else to do
}

FunctionDefinition::FunctionDefinition(std::string name_, std::vector<AstNode *> children_) :
    Definition(name_),
    Block(children_)
{
    // Nothing else to do
}

FunctionDefinition::~FunctionDefinition()
{
    // Nothing else to do
}

int FunctionDefinition::walkTree()
{
    std::cout << "Entering function definition \"" << name << "\", exploring block." << std::endl;
    Block::walkTree();
    return 0;
}