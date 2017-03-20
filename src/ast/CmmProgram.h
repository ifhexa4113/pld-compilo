#ifndef CMM_PROGRAM_H
#define CMM_PROGRAM_H

#include <vector>

#include "AstNode.h"

class CmmProgram : public AstNode {

public:
    CmmProgram();
    ~CmmProgramm();

    virtual int walkTree();
    void addFunction(FunctionDefinition* function);

protected:
    SymbolTable* symbolTable;
    std::vector<FunctionDefinition*> functions;
};

#endif