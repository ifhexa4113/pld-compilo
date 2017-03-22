#include <iostream>

#include "Block.h"

Block::Block(std::vector<AstNode*>* children_) :
    AstNode(),
    children(children_)
{

}

Block::~Block()
{
    for(auto it = children->begin(); it != children->end(); ++it)
        delete (*it);
    if(children != nullptr)
        delete children;
}

int Block::walkTree()
{
    std::cout << "Entering Block, exploring its children." << std::endl;
    for(auto it = children->begin(); it != children->end(); ++it)
    {
        (*it)->walkTree();
    }
    return 0;
}