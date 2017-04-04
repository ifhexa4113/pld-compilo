//
// Created by Element on 29/03/2017.
//

#include "ModInstruction.h"

ModInstruction::ModInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

ModInstruction::~ModInstruction() {
    if(!dynamic_cast<Register*>(param1))
    {
        delete param1;
    }
    if(!dynamic_cast<Register*>(param2))
    {
        delete param2;
    }
}

void ModInstruction::print(std::ostream &ost) const {
    ost << "MUL\t" << *destination << ", " << *param1 << ", " << *param2 << std::endl;
}

Operand *ModInstruction::getParam1() const {
    return param1;
}

Operand *ModInstruction::getParam2() const {
    return param2;
}
