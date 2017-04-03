//
// Created by Element on 29/03/2017.
//

#include "WriteInstruction.h"

WriteInstruction::WriteInstruction(Operand *address, Operand *value) : IRInstruction(), address(address), value(value) {

}

WriteInstruction::~WriteInstruction() {
    if(!dynamic_cast<Register*>(address))
    {
        delete address;
    }
    if(!dynamic_cast<Register*>(value))
    {
        delete value;
    }
}

void WriteInstruction::print(std::ostream &ost) const {
    ost << "WRITE\t" << address << ", " << value;
}

const Operand *WriteInstruction::getAddress() const {
    return address;
}

const Operand *WriteInstruction::getValue() const {
    return value;
}
