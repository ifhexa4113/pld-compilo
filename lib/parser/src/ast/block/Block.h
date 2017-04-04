#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include "ast/AstNode.h"
#include "ast/SymbolTable.h"
#include "ast/declaration/Type.h"

class Block: public virtual AstNode
{
public:
    Block();
    Block(std::vector<AstNode*> children_);
    virtual ~Block();
    virtual int walkTree();
    std::vector<AstNode*> getChildren();
    void addChildren(AstNode* child);

    virtual void fillSymbolTable(SymbolTableStack& stack);
    virtual void fillAstTrace(std::string& astTrace);
    
    bool checkReturnType(Type type, SymbolTableStack& stack);

protected:
    SymbolTable symbolTable;
    std::vector<AstNode*> children;
};

#endif //BLOCK_H
