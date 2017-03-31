//
// Created by Element on 29/03/2017.
//

#include "LshiftInstruction.h"

LshiftInstruction::LshiftInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

LshiftInstruction::~LshiftInstruction() {
    delete param1;
    delete param2;
}

void LshiftInstruction::print(std::ostream &ost) const {
    ost << "AND\t" << destination << ", " << param1 << ", " << param2;
}

Operand *LshiftInstruction::getParam1() const {
    return param1;
}

Operand *LshiftInstruction::getParam2() const {
    return param2;
}
