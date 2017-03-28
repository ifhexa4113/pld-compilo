#include "MovInstruction.h"

MovInstruction::MovInstruction(Register aRegister, unsigned int value_) :
    IRInstruction(), reg(aRegister), value(value_)
{
    // Nothing else to do
}

MovInstruction::~MovInstruction()
{
    // Nothing else to do
}

void MovInstruction::print(std::ostream& ost) const
{
    ost << "MOV " << reg.getName() << ", #" << value << std::endl;
}