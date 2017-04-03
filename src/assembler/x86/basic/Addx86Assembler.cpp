//
// Created by Element on 02/04/2017.
//

#include <sstream>
#include "Addx86Assembler.h"
#include "assembler/x86/operand/Operandx86Assembler.h"
#include "Movx86Assembler.h"

Addx86Assembler::Addx86Assembler(AddInstruction *instruction) : AddAbstractAssembler(instruction, nullptr) {}

Addx86Assembler::~Addx86Assembler() {

}

std::string Addx86Assembler::translate() const {
    Operandx86Assembler dest(instruction->getDestination());
    Operandx86Assembler param1(instruction->getParam1());
    Operandx86Assembler param2(instruction->getParam2());

    std::ostringstream stm;

    /*
     *  add <reg>,<reg>
     *  add <reg>,<mem>
     *  add <mem>,<reg>
     *  add <reg>,<con>
     *  add <mem>,<con>
     */

    // Handle different dest and param1
    if (dest.getValue() != param1.getValue())
    {
        stm << Movx86Assembler::getString(param1, dest);
    }

    // Handle 2 memory param : put second operand in register
    // Handle : add <mem>, <mem>
    if (dest.getType() == Operandx86Assembler::operand_type::VIRTUAL_REGISTER && param2.getType() == Operandx86Assembler::operand_type::VIRTUAL_REGISTER)
    {
        // Mov param2 in a register
        stm << Movx86Assembler::getString(param2, Operandx86Assembler::getWorkRegister(Operandx86Assembler::work_register::SOURCE));

        // Set param2 as the work register
        param2 = Operandx86Assembler::getWorkRegister(Operandx86Assembler::work_register::SOURCE);
    }

    // Do the add Operation
    stm << "add " << dest.toString() << ", " << param2.toString() << std::endl;

    return stm.str();
}
