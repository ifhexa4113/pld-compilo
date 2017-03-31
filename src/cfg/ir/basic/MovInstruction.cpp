#include "MovInstruction.h"

MovInstruction::MovInstruction(Register* destination_, Operand* source_) :
    RegisterInstruction(destination_), source(source_)
{
    // Nothing else to do
}

MovInstruction::~MovInstruction()
{
    delete destination;
    delete source;
}

void MovInstruction::print(std::ostream& ost) const
{
    ost << "MOV\t" << *destination << ", " << *source << std::endl;
}