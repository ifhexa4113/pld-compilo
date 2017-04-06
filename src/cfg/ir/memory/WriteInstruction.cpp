//
// Created by Element on 29/03/2017.
//

#include "WriteInstruction.h"

WriteInstruction::WriteInstruction(Operand *address, Operand *value) : IRInstruction(), address(address), value(value) {

}

WriteInstruction::~WriteInstruction()
{
    // Nothing else to do (the Table handles it)
}

void WriteInstruction::print(std::ostream &ost) const {
    ost << "WRITE\t" << *address << ", " << *value << std::endl;
}

const Operand *WriteInstruction::getAddress() const {
    return address;
}

const Operand *WriteInstruction::getValue() const {
    return value;
}
