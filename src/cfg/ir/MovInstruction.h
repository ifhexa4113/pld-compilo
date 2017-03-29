#ifndef MOV_INSTRUCTION_H
#define MOV_INSTRUCTION_H

#include "IRInstruction.h"
#include "Register.h"

class MovInstruction : public IRInstruction
{
public:
    MovInstruction(Register* aRegister, Register* bRegister);
    ~MovInstruction();
    void print(std::ostream& ost) const;

protected:
    Register* regA;
    Register* regB;
    unsigned int value;
};


#endif //MOV_INSTRUCTION_H
