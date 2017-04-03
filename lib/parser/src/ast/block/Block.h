#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "ast/AstNode.h"
#include "ast/SymbolTable.h"

class Block: public virtual AstNode
{
public:
    Block();
    Block(std::vector<AstNode*> children_);
    virtual ~Block();
    virtual int walkTree();
    SymbolTable getSymbolTable();
    std::vector<AstNode*> getChildren();
    void addChildren(AstNode* child);

protected:
    SymbolTable symbolTable;
    std::vector<AstNode*> children;
};

#endif //BLOCK_H
