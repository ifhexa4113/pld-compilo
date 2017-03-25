#ifndef CONTINUE_INSTRUCTION_H
#define CONTINUE_INSTRUCTION_H

#include "ast/AstNode.h"

class ContinueInstruction : public AstNode
{
public:
    ContinueInstruction();
    int walkTree();
};

#endif