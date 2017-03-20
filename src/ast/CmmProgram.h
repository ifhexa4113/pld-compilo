#ifndef CMM_PROGRAM_H
#define CMM_PROGRAM_H

#include <vector>

#include "AstNode.h"
#include "block/block-class/FunctionDefinition.h"
#include "symbol_table/SymbolTable.h"

class CmmProgram : public AstNode {

public:
    CmmProgram();
    virtual ~CmmProgram();

    virtual int walkTree();
    void addFunction(FunctionDefinition* function);

protected:
    SymbolTable symbolTable;
    std::vector<FunctionDefinition*> functions;
};

#endif