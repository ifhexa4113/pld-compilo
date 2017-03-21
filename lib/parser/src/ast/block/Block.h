#ifndef BLOCK_H
#define BLOCK_H

#include <deque>

#include "../AstNode.h"
#include "../symbol_table/SymbolTable.h"

class Block: public AstNode {

public:
    Block(std::deque<AstNode*>* childrens_ = nullptr);
    virtual ~Block();
    
    virtual int walkTree();

protected:
    SymbolTable symbolTable;
    std::deque<AstNode*>* childrens;
};

#endif //BLOCK_H
