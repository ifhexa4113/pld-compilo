#ifndef MOV_INSTRUCTION_H
#define MOV_INSTRUCTION_H

#include "IRInstruction.h"
#include "Operand.h"
#include "Register.h"

class MovInstruction : IRInstruction
{
public:
    MovInstruction(Register* destination_, Operand* source_);
    ~MovInstruction();
    void print(std::ostream& ost) const;

protected:
    Register* destination;
    Operand* source;
};


#endif //MOV_INSTRUCTION_H
