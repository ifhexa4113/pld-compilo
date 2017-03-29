//
// Created by Element on 29/03/2017.
//

#include "AndInstruction.h"

AndInstruction::AndInstruction(Register *destination, Operand *param1, Operand *param2)
        : IRInstruction(), destination(destination), param1(param1), param2(param2) {

}

AndInstruction::~AndInstruction() {
    delete destination;
    delete param1;
    delete param2;
}

void AndInstruction::print(std::ostream &ost) const {
    ost << "AND\t" << destination << ", " << param1 << ", " << param2;
}

Register *AndInstruction::getDestination() const {
    return destination;
}

Operand *AndInstruction::getParam1() const {
    return param1;
}

Operand *AndInstruction::getParam2() const {
    return param2;
}
