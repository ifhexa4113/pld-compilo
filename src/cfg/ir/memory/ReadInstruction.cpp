//
// Created by Element on 29/03/2017.
//

#include "ReadInstruction.h"

ReadInstruction::ReadInstruction(Register *destination, Operand *address) : RegisterInstruction(destination), address(address) {

}

ReadInstruction::~ReadInstruction() {
    if(!dynamic_cast<Register*>(address))
    {
        delete address;
    }
}

void ReadInstruction::print(std::ostream &ost) const {
    ost << "READ\t" << destination << ", " << address << std::endl;
}

const Operand *ReadInstruction::getAddress() const {
    return address;
}
