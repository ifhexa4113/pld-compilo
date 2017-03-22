#ifndef BLOCK_H
#define BLOCK_H

#include <vector>

#include "../AstNode.h"
#include "../symbol_table/SymbolTable.h"

class Block: public AstNode {

public:
    Block(std::vector<AstNode*>* children_ = nullptr);
    virtual ~Block();
    
    virtual int walkTree();

protected:
    SymbolTable symbolTable;
    std::vector<AstNode*>* children;
};

#endif //BLOCK_H
