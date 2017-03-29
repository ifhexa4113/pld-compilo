//
// Created by Element on 29/03/2017.
//

#include "OrInstruction.h"

OrInstruction::OrInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

OrInstruction::~OrInstruction() {
    delete param1;
    delete param2;
}

void OrInstruction::print(std::ostream &ost) const {
    ost << "AND\t" << destination << ", " << param1 << ", " << param2;
}

Operand *OrInstruction::getParam1() const {
    return param1;
}

Operand *OrInstruction::getParam2() const {
    return param2;
}
