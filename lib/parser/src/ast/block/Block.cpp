#include <iostream>

#include "Block.h"

Block::Block(std::deque<AstNode*>* childrens_) :
    AstNode(),
    childrens(childrens_)
{

}

Block::~Block()
{
    for(auto it = childrens->begin(); it != childrens->end(); ++it)
        delete (*it);
    if(childrens != nullptr)
        delete childrens;
}

int Block::walkTree()
{
    std::cout << "Entering Block, exploring its childrens." << std::endl;
    for(auto it = childrens->begin(); it != childrens->end(); ++it)
    {
        (*it)->walkTree();
    }
    return 0;
}