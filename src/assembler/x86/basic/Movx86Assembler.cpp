//
// Created by Element on 02/04/2017.
//

#include <sstream>
#include <iostream>
#include "Movx86Assembler.h"

Movx86Assembler::Movx86Assembler(MovInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : MovAbstractAssembler(instruction, parent_block) {

}

Movx86Assembler::~Movx86Assembler() {

}

std::string Movx86Assembler::translate() const {
    std::cout << "Tranlating mov instruction " << parent_block << " instr " << instruction << std::endl;
    instruction->getSource();
    std::cout << "Get source is clean";

    return getString(
            Operandx86Assembler(instruction->getSource(),parent_block),
            Operandx86Assembler(instruction->getDestination(), parent_block));
}

std::string Movx86Assembler::getString(Operandx86Assembler source, Operandx86Assembler dest) {
    std::ostringstream stm;
    #ifdef __linux__
        std::string op_suffix = "l";
    #elif _WIN32
        std::string op_suffix = "l";
    #endif
    std::cout << "Day 247, still putting std::cout in my code to find where the fuck the code crashes ..." << std::endl;
    if (source.getType() == Operandx86Assembler::operand_type::VIRTUAL_REGISTER && dest.getType() == Operandx86Assembler::operand_type::VIRTUAL_REGISTER)
    {
        Operandx86Assembler temp_register = Operandx86Assembler::getPhysicalRegister(Operandx86Assembler::register_type::A);
        stm << "\tmov" << op_suffix << "\t" << source.toString() << ", " << temp_register.toString() << std::endl;
        stm << "\tmov" << op_suffix << "\t" << temp_register.toString() << ", " << dest.toString() << std::endl;
    }
    else
    {
        stm << "\tmov" << op_suffix << "\t" << source.toString() << ", " << dest.toString() << std::endl;
    }

    return stm.str();
}
