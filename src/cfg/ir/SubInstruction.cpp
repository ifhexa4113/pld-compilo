//
// Created by Element on 29/03/2017.
//

#include "SubInstruction.h"

SubInstruction::SubInstruction(Register *destination_, Operand *param1_, Operand *param2_)
        : IRInstruction(), destination(destination_), param1(param1_), param2(param2_) {

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
