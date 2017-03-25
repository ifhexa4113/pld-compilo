#ifndef CMM_PROGRAM_H
#define CMM_PROGRAM_H

#include <vector>
#include "Block.h"
#include "ast/AstNode.h"
#include "ast/definition/FunctionDefinition.h"
#include "ast/SymbolTable.h"

class CmmProgram : public Block
{
public:
    CmmProgram();
    CmmProgram(std::vector<AstNode*> children_);
    ~CmmProgram();

    int walkTree();
    void addFunction(FunctionDefinition* function);
};

#endif