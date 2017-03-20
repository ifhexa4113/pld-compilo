
#ifndef BLOCK_H
#define BLOCK_H

#include "AstNode.h"

class BlockClass: public AstNode{

public:
    Block();
    ~Block();

    virtual void WalkTree();
    void addChild();

protected:
    SymbolTable symbolTable;
    std::vector<AstNode> childrens;
};

#endif //BLOCK_H
