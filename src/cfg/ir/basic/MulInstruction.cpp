//
// Created by Element on 29/03/2017.
//

#include "MulInstruction.h"

MulInstruction::MulInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

MulInstruction::~MulInstruction()
{
    // Nothing else to do (the Table handles it)
}

void MulInstruction::print(std::ostream &ost) const {
    ost << "MUL\t" << *destination << ", " << *param1 << ", " << *param2 << std::endl;
}

Operand *MulInstruction::getParam1() const {
    return param1;
}

Operand *MulInstruction::getParam2() const {
    return param2;
}
