//
// Created by Element on 29/03/2017.
//

#include "XorInstruction.h"

XorInstruction::XorInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

XorInstruction::~XorInstruction()
{
    // Nothing else to do (the Table handles it)
}

void XorInstruction::print(std::ostream &ost) const {
    ost << "XOR\t" << *destination << ", " << *param1 << ", " << *param2 << std::endl;
}

Operand *XorInstruction::getParam1() const {
    return param1;
}

Operand *XorInstruction::getParam2() const {
    return param2;
}
