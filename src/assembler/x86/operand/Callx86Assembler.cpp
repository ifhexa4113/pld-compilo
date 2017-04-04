//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include <assembler/x86/basic/Movx86Assembler.h>
#include "Callx86Assembler.h"

Callx86Assembler::Callx86Assembler(CallInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : CallAbstractAssembler(instruction,
                                parent_block) {

}

Callx86Assembler::~Callx86Assembler() {

}

std::string Callx86Assembler::translate() const {
    std::ostringstream stream;
    std::vector<Register*> & registers= instruction->getRegisters();

    for (int param_index = registers.size() - 1; param_index >=0 ; param_index ++)
    {
        stream << Movx86Assembler::getString(Operandx86Assembler::getVirtualRegister(
                       parent_block->getOffset(registers.at(param_index))),Operandx86Assembler(registers.at(param_index),parent_block));
    }

    stream << "call " << instruction->getLabel() << std::endl;
    return stream.str();
}
