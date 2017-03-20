#include "Block.h"

Block::Block() : 
    AstNode()
{

}

Block::~Block()
{
    for(auto child : childrens)
        delete child;
}

void Block::addChild(AstNode* child){
        childrens.push_back(child);
};

int Block::walkTree()
{

}