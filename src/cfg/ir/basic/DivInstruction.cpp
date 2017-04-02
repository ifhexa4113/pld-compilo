//
// Created by Element on 29/03/2017.
//

#include "DivInstruction.h"

DivInstruction::DivInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

DivInstruction::~DivInstruction() {
    delete param1;
    delete param2;
}

void DivInstruction::print(std::ostream &ost) const {
    ost << "MUL\t" << destination << ", " << param1 << ", " << param2;
}

Operand *DivInstruction::getParam1() const {
    return param1;
}

Operand *DivInstruction::getParam2() const {
    return param2;
}
