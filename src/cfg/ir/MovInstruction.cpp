#include "MovInstruction.h"

MovInstruction::MovInstruction(Register* aRegister, Register* bRegister) :
    IRInstruction(), regA(aRegister), regB(bRegister)
{
    // Nothing else to do
}

MovInstruction::~MovInstruction()
{
    // Nothing else to do
}

void MovInstruction::print(std::ostream& ost) const
{
    ost << "MOV " << regA->getName() << ", " << regB->getName() << std::endl;
}