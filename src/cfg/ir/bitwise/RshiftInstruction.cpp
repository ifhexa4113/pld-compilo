//
// Created by Element on 29/03/2017.
//

#include "RshiftInstruction.h"

RshiftInstruction::RshiftInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

RshiftInstruction::~RshiftInstruction() {
    if(!dynamic_cast<Register*>(param1))
    {
        delete param1;
    }
    if(!dynamic_cast<Register*>(param2))
    {
        delete param2;
    }
}

void RshiftInstruction::print(std::ostream &ost) const {
    ost << "AND\t" << destination << ", " << param1 << ", " << param2;
}

Operand *RshiftInstruction::getParam1() const {
    return param1;
}

Operand *RshiftInstruction::getParam2() const {
    return param2;
}
