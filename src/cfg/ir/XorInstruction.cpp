//
// Created by Element on 29/03/2017.
//

#include "XorInstruction.h"

XorInstruction::XorInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

XorInstruction::~XorInstruction() {
    delete param1;
    delete param2;
}

void XorInstruction::print(std::ostream &ost) const {
    ost << "AND\t" << destination << ", " << param1 << ", " << param2;
}

Operand *XorInstruction::getParam1() const {
    return param1;
}

Operand *XorInstruction::getParam2() const {
    return param2;
}