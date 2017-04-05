//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include <map>
#include <assembler/x86/basic/Movx86Assembler.h>
#include <cfg/ir/jump/CallInstruction.h>
#include <assembler/x86/jump/Callx86Assembler.h>
#include <iostream>
#include <cfg/ir/basic/AddInstruction.h>
#include <assembler/x86/basic/Addx86Assembler.h>
#include "x86BasicBlockAssembler.h"


x86BasicBlockAssembler::x86BasicBlockAssembler(BasicBlock *source, bool generate_intro)
        : AbstractBasicBlockAssembler(source, generate_intro) {

}

std::string x86BasicBlockAssembler::generateProlog() {

    std::ostringstream stream;
    //std::cout << "WAT THE FUCK " << variable_count * 4 << std::endl;

    // pushl %epb
    // movl %esp, %epb
    // subl $variable_count * 4, %esp

    // PAS LE TEMPS DE NIAISER
    stream << "\tpushl\t%ebp" << std::endl;
    stream << "\tmovl\t%esp, %ebp" << std::endl;
    stream << "\tsubl\t$" << variable_count * 4 << ", %esp" << std::endl;
    //std::cout << "WAT THE FUCK " << variable_count * 4 << std::endl;

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
    std::ostringstream stream;

    stream << "\tmovl\t$0, %eax" << std::endl;
    stream << "\tleave" << std::endl;
    stream << "\tret" << std::endl;

    return stream.str();
}

IRAbstractAssembler * x86BasicBlockAssembler::translateInstruction(IRInstruction *instruction) {


    if (dynamic_cast<MovInstruction *>(instruction) != nullptr)
    {

        return new Movx86Assembler((MovInstruction*)instruction, this);
    }
    else if (dynamic_cast<CallInstruction *>(instruction) != nullptr)
    {
        return new Callx86Assembler((CallInstruction*) instruction, this);
    }
    else if (dynamic_cast<AddInstruction *>(instruction) != nullptr)
    {
        return new Addx86Assembler((AddInstruction*) instruction, this);
    }

    return nullptr;
}

std::string x86BasicBlockAssembler::getLabel() {
    std::ostringstream stream;
    stream <<"_" << source->getLabel() << ":" << std::endl;

    return stream.str();
}

std::string x86BasicBlockAssembler::getIntro() {
    std::ostringstream stream;

    stream << "\t.text" << std::endl;
    stream << "\t.globl\t_main" << std::endl;

    return stream.str();
}
