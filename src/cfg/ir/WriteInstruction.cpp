//
// Created by Element on 29/03/2017.
//

#include "WriteInstruction.h"

WriteInstruction::WriteInstruction(Operand address, Operand value) : IRInstruction() {

}

WriteInstruction::~WriteInstruction() {

}

void WriteInstruction::print(std::ostream &ost) const {
    ost << "WRITE\t" << address << ", " << value;
}
