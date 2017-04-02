//
// Created by Element on 29/03/2017.
//

#include "CmpInstruction.h"

CmpInstruction::CmpInstruction(Operand *address, Operand *value) : IRInstruction(), address(address), value(value) {

}

CmpInstruction::~CmpInstruction() {
    delete address;
    delete value;
}

void CmpInstruction::print(std::ostream &ost) const {
    ost << "CMP\t" << address << ", " << value;
}

const Operand *CmpInstruction::getAddress() const {
    return address;
}

const Operand *CmpInstruction::getValue() const {
    return value;
}
