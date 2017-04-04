#ifndef CONTINUE_INSTRUCTION_H
#define CONTINUE_INSTRUCTION_H

#include "ast/AstNode.h"

class ContinueInstruction : public AstNode
{
public:
    ContinueInstruction();
    int walkTree();
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type type, SymbolTableStack& stack){return false;};
};

#endif