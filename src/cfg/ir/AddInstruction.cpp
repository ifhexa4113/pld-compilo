//
// Created by Element on 29/03/2017.
//

#include "AddInstruction.h"

AddInstruction::AddInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

AddInstruction::~AddInstruction() {
    delete param1;
    delete param2;
}

void AddInstruction::print(std::ostream &ost) const {
    ost << "ADD\t" << destination << ", " << param1 << ", " << param2;
}

Operand *AddInstruction::getParam1() const {
    return param1;
}

Operand *AddInstruction::getParam2() const {
    return param2;
}