#ifndef RETURN_H
#define RETURN_H

#include "Instruction.h"
#include "ast/expression/Expression.h"

class ReturnInstruction : public Instruction
{
public:
    ReturnInstruction(Expression* value_);
    ~ReturnInstruction();
    int walkTree();
    Expression* getValue() const;

protected:
    Expression* value;
};

#endif