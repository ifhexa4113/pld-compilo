//
// Created by Element on 29/03/2017.
//

#include "AddInstruction.h"

AddInstruction::AddInstruction(Register *destination_, Operand *param1_, Operand *param2_)
        : RegisterInstruction(destination_), param1(param1_), param2(param2_) {

}

AddInstruction::~AddInstruction() {
    delete param1;
    delete param2;
}

void AddInstruction::print(std::ostream &ost) const {
    ost << "ADD\t" << destination << ", " << param1 << ", " << param2;
}

Register *AddInstruction::getDestination() const {
    return destination;
}

Operand *AddInstruction::getParam1() const {
    return param1;
}

Operand *AddInstruction::getParam2() const {
    return param2;
}
