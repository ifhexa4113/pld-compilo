#ifndef MOV_INSTRUCTION_H
#define MOV_INSTRUCTION_H

#include "IRInstruction.h"
#include "Register.h"

class MovInstruction : IRInstruction
{
public:
    MovInstruction(Register aRegister, unsigned int value_);
    ~MovInstruction();
    void print(std::ostream& ost) const;

protected:
    Register reg;
    unsigned int value;
};


#endif //MOV_INSTRUCTION_H
