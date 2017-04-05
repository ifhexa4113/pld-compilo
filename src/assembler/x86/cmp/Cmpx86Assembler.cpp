//
// Created by Element on 05/04/2017.
//

#include <sstream>
#include <assembler/x86/basic/Movx86Assembler.h>
#include "Cmpx86Assembler.h"
#include "assembler/x86/operand/Operandx86Assembler.h"

Cmpx86Assembler::Cmpx86Assembler(CmpInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : CmpAbstractAssembler(instruction, parent_block) {

}

Cmpx86Assembler::~Cmpx86Assembler() {

}

std::string Cmpx86Assembler::translate() const {
    Operandx86Assembler tmpRegister = Operandx86Assembler::getPhysicalRegister(Operandx86Assembler::register_type::A);
    Operandx86Assembler param1(instruction->getParam1(), parent_block);
    Operandx86Assembler param2(instruction->getParam2(), parent_block);
    std::ostringstream stream;


    stream << Movx86Assembler::getString(param2, tmpRegister);
    stream << "\tcmp \t" << tmpRegister.toString() << ", " << param1.toString() << std::endl;

    return stream.str();
}
