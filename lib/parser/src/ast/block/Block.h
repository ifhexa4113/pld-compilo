#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "../AstNode.h"
#include "../symbol_table/SymbolTable.h"

class Block: public AstNode{

public:
    Block();
    virtual ~Block();
    virtual int walkTree();
    void addChild(AstNode* child);

protected:
    SymbolTable symbolTable;
    std::vector<AstNode*> childrens;
};

#endif //BLOCK_H
