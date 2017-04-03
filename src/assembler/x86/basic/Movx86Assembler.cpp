//
// Created by Element on 02/04/2017.
//

#include <sstream>
#include "Movx86Assembler.h"

Movx86Assembler::Movx86Assembler(MovInstruction *instruction) : MovAbstractAssembler(instruction) {

}

Movx86Assembler::~Movx86Assembler() {

}

std::string Movx86Assembler::translate() const {
    return nullptr;
}

std::string Movx86Assembler::getString(Operandx86Assembler source, Operandx86Assembler dest) {
    std::ostringstream stm;

    stm << "mov" << dest.toString() << ", " << source.toString() << std::endl;

    return stm.str();
}
