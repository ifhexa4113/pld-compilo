#include "MovInstruction.h"

MovInstruction::MovInstruction(Register* destination_, Operand* source_) :
    RegisterInstruction(destination_), source(source_)
{
    // Nothing else to do
}

MovInstruction::~MovInstruction()
{
    // Nothing else to do (the Table handles it)
}

void MovInstruction::print(std::ostream& ost) const
{
    ost << "MOV\t" << *destination << ", " << *source << std::endl;
}