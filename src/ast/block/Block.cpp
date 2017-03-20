#include "Block.h"

Block::Block()
{
#ifdef DEBUG
    id = AstNode.IdMax++;
        std::cout << "Creating Block node, id: " << id << std::endl;
#endif
}

Block::~Block()
{
    delete symbolTable;
    for(auto child : childrens)
        delete child;
}

void Block::addChild(AstNode* child){
        this.childrens.push_back(child);
};