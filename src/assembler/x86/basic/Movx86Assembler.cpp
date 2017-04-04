//
// Created by Element on 02/04/2017.
//

#include <sstream>
#include "Movx86Assembler.h"

Movx86Assembler::Movx86Assembler(MovInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : MovAbstractAssembler(instruction, parent_block) {

}

Movx86Assembler::~Movx86Assembler() {

}

std::string Movx86Assembler::translate() const {
    return getString(Operandx86Assembler(instruction->getSource(),parent_block),Operandx86Assembler(instruction->getDestination(), parent_block));
}

std::string Movx86Assembler::getString(Operandx86Assembler source, Operandx86Assembler dest) {
    std::ostringstream stm;

    stm << "mov\t" << source.toString() << ", " << dest.toString() << std::endl;

    return stm.str();
}
