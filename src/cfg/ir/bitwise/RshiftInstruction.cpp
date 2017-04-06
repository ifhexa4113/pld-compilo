//
// Created by Element on 29/03/2017.
//

#include "RshiftInstruction.h"

RshiftInstruction::RshiftInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

RshiftInstruction::~RshiftInstruction()
{
    // Nothing else to do (the Table handles it)
}

void RshiftInstruction::print(std::ostream &ost) const {
    ost << "RSHIFT\t" << *destination << ", " << *param1 << ", " << *param2 << std::endl;
}

Operand *RshiftInstruction::getParam1() const {
    return param1;
}

Operand *RshiftInstruction::getParam2() const {
    return param2;
}
