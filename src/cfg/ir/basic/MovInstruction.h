#ifndef MOV_INSTRUCTION_H
#define MOV_INSTRUCTION_H

#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Operand.h"
#include "cfg/ir/operand/Register.h"

class MovInstruction : public RegisterInstruction
{
public:
    MovInstruction(Register* destination_, Operand* source_);
    ~MovInstruction();
    void print(std::ostream& ost) const;

protected:
    Operand* source;
public:
    Operand *getSource() const;
};


#endif //MOV_INSTRUCTION_H
