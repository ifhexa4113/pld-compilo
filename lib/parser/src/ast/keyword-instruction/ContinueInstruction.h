#ifndef CONTINUE_INSTRUCTION_H
#define CONTINUE_INSTRUCTION_H

#include "ast/AstNode.h"

class ContinueInstruction : public AstNode
{
public:
    ContinueInstruction();
    int walkTree();
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type, SymbolTableStack&){return false;};
};

#endif