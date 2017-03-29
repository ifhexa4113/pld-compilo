//
// Created by Element on 29/03/2017.
//

#include "ReadInstruction.h"

ReadInstruction::ReadInstruction(Register destination, Operand address) : IRInstruction() ,  destination(destination), address(address) {

}

ReadInstruction::~ReadInstruction() {

}

void ReadInstruction::print(std::ostream &ost) const {
    ost << "READ\t" << destination << ", " << address << std::endl;
}

const Register &ReadInstruction::getDestination() const {
    return destination;
}

const Operand &ReadInstruction::getAddress() const {
    return address;
}
