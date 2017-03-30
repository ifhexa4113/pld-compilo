#ifndef MOV_INSTRUCTION_H
#define MOV_INSTRUCTION_H

#include "RegisterInstruction.h"
#include "Operand.h"
#include "Register.h"

class MovInstruction : public RegisterInstruction
{
public:
    MovInstruction(Register* destination_, Operand* source_);
    ~MovInstruction();
    void print(std::ostream& ost) const;

protected:
    Operand* source;
};


#endif //MOV_INSTRUCTION_H
