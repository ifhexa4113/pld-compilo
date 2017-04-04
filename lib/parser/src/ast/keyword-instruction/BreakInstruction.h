#ifndef BREAK_INSTRUCTION_H
#define BREAK_INSTRUCTION_H

#include "../AstNode.h"

class BreakInstruction : public AstNode
{
public:
    BreakInstruction();
    int walkTree();
    void fillAstTrace(std::string& astTrace);
    bool checkReturnType(Type type, SymbolTableStack& stack){return false;};
};

#endif