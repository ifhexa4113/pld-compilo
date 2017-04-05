//
// Created by Element on 29/03/2017.
//

#include "OrInstruction.h"

OrInstruction::OrInstruction(Register *destination, Operand *param1, Operand *param2)
        : RegisterInstruction(destination), param1(param1), param2(param2) {

}

OrInstruction::~OrInstruction()
{
    // Nothing else to do (the Table handles it)
}

void OrInstruction::print(std::ostream &ost) const {
    ost << "OR\t" << *destination << ", " << *param1 << ", " << *param2 << std::endl;
}

Operand *OrInstruction::getParam1() const {
    return param1;
}

Operand *OrInstruction::getParam2() const {
    return param2;
}
