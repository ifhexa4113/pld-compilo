//
// Created by Element on 29/03/2017.
//

#include "LshiftInstruction.h"

LshiftInstruction::LshiftInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

LshiftInstruction::~LshiftInstruction()
{
    // Nothing else to do (the Table handles it)
}

void LshiftInstruction::print(std::ostream &ost) const {
    ost << "LSHIFT\t" << *destination << ", " << *param1 << ", " << *param2 << std::endl;
}

Operand *LshiftInstruction::getParam1() const {
    return param1;
}

Operand *LshiftInstruction::getParam2() const {
    return param2;
}
