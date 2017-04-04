//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include "Callx86Assembler.h"

Callx86Assembler::Callx86Assembler(CallInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : CallAbstractAssembler(instruction,
                                parent_block) {

}

Callx86Assembler::~Callx86Assembler() {

}

std::string Callx86Assembler::translate() const {
    std::ostringstream stream;
    instruction->getRegisters();
    //for (Register * re)

    stream << "call" << std::endl;
    return stream.str();
}
