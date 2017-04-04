//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include <map>
#include <assembler/x86/basic/Movx86Assembler.h>
#include <cfg/ir/jump/CallInstruction.h>
#include <assembler/x86/operand/Callx86Assembler.h>
#include <iostream>
#include "x86BasicBlockAssembler.h"


x86BasicBlockAssembler::x86BasicBlockAssembler(BasicBlock *source) : AbstractBasicBlockAssembler(source){

}

std::string x86BasicBlockAssembler::generateProlog() {

    std::ostringstream stream;

    // pushl %epb
    // movl %esp, %epb
    // subl $variable_count * 4, %esp

    // PAS LE TEMPS DE NIAISER
    stream << "pushl %epb" << std::endl;
    stream << "movl %esp, %epb" << std::endl;
    stream << "subl " << variable_count * 4 << ", %esp" << std::endl;
    
    return stream.str();
}

std::string x86BasicBlockAssembler::translateIR() {
    std::ostringstream stream;

    std::vector<IRInstruction *> instructions = source->getInstructions();

    for (int current_index = 0; current_index < instructions.size(); current_index ++)
    {
        IRAbstractAssembler * translated_instruction = translateInstruction(instructions[current_index]);

        if (translated_instruction != nullptr)
        {
            //std::cout << "Translated mov instruction" << std::endl;
            stream << translated_instruction->translate();
        }
    }

    return stream.str();
}

std::string x86BasicBlockAssembler::generateEpilog() {
    return "";
}

IRAbstractAssembler * x86BasicBlockAssembler::translateInstruction(IRInstruction *instruction) {

    MovInstruction * mov = nullptr;
    CallInstruction * call = nullptr;

    if ((mov = dynamic_cast<MovInstruction *>(instruction)) != nullptr)
    {

        return new Movx86Assembler(mov, this);
    }
    else if ((call = dynamic_cast<CallInstruction *>(instruction)) != nullptr)
    {
        return new Callx86Assembler(call, this);
    }

    return nullptr;
}

std::string x86BasicBlockAssembler::getLabel() {
    std::ostringstream stream;
    stream << source->getLabel() << ":" << std::endl;

    return stream.str();
}
