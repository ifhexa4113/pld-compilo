#include <iostream>
#include "Block.h"

Block::Block() :
    AstNode()
{
    // Nothing else to do
}

Block::Block(std::vector<AstNode*> children_) :
    AstNode(),
    children(children_)
{
    // TODO: fill symbols table
}

Block::~Block()
{
    for(auto child : children)
    {
        delete child;
    }
}

int Block::walkTree()
{
    std::cout << "Entering Block, exploring its children." << std::endl;
    for(auto child : children)
    {
        child->walkTree();
    }
    return 0;
}