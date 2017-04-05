//
// Created by Element on 29/03/2017.
//

#include "NotInstruction.h"

NotInstruction::NotInstruction(Register *destination, Operand *source) : RegisterInstruction(destination), source(source){

}

NotInstruction::~NotInstruction()
{
    // Nothing else to do (the Table handles it)
}

void NotInstruction::print(std::ostream &ost) const {
    ost << "NOT\t" << *destination << ", " << *source << std::endl;
}

Operand *NotInstruction::getSource() const {
    return source;
}
