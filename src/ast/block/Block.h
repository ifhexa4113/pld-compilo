
#ifndef BLOCK_H
#define BLOCK_H

#include "AstNode.h"

class Block: public AstNode{

public:
    Block();
    ~Block();
    virtual int WalkTree();
    void addChild();

protected:
    SymbolTable symbolTable;
    std::vector<AstNode*> childrens;
};

#endif //BLOCK_H
