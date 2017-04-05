//
// Created by Element on 29/03/2017.
//

#include "ReadInstruction.h"

ReadInstruction::ReadInstruction(Register *destination, Operand *address) : RegisterInstruction(destination), address(address) {

}

ReadInstruction::~ReadInstruction() {
    // Nothing else to do (the Table handles it)
}

void ReadInstruction::print(std::ostream &ost) const {
    ost << "READ\t" << *destination << ", " << *address << std::endl;
}

const Operand *ReadInstruction::getAddress() const {
    return address;
}
