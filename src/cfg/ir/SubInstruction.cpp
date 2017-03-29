//
// Created by Element on 29/03/2017.
//

#include "SubInstruction.h"

SubInstruction::SubInstruction(Register *destination, Operand *param1, Operand *param2)
        : IRInstruction(), destination(destination), param1(param1), param2(param2) {
}

SubInstruction::~SubInstruction() {
    delete destination;
    delete param1;
    delete param2;
}

void SubInstruction::print(std::ostream &ost) const {
    ost << "SUB\t" << destination << ", " << param1 << ", " << param2;
}

Register *SubInstruction::getDestination() const {
    return destination;
}

Operand *SubInstruction::getParam1() const {
    return param1;
}

Operand *SubInstruction::getParam2() const {
    return param2;
}
