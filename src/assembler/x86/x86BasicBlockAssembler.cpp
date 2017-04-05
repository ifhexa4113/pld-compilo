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
#ifdef __linux__
    stream << "\tpushq\t%rbp" << std::endl;
    stream << "\tmovq\t%rsp, %rbp" << std::endl;
    stream << "\tsubq\t$" << variable_count * 4 << ", %esp" << std::endl;
#elif _WIN32
    stream << "\tpushl\t%ebp" << std::endl;
    stream << "\tmovl\t%esp, %ebp" << std::endl;
    stream << "\tsubl\t$" << variable_count * 4 << ", %esp" << std::endl;
#endif

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
    stream << x86BasicBlockAssembler::getLabelPrefix() << source->getLabel() << ":" << std::endl;
    return stream.str();
}

std::string x86BasicBlockAssembler::getIntro() {
    std::ostringstream stream;

    stream << "\t.text" << std::endl;
    stream << "\t.globl\t" << getLabelPrefix() << "main" << std::endl;

    return stream.str();
}

std::string x86BasicBlockAssembler::getJump(std::string label, BasicBlock::JumpType jumpType) {
    std::ostringstream stream;

    std::cout << "Entering jump generation " << std::endl;
    stream << "\t";

    switch (jumpType) {
        case BasicBlock::JumpType::NUL : {
            stream << "jmp ";
            break;
        }
        case BasicBlock::JumpType::Z : {
            stream << "je ";
            break;
        }
        case BasicBlock::JumpType::NZ : {
            stream << "jne ";
            break;
        }
        case BasicBlock::JumpType::N : {
            stream << "jl ";
        }
        default :
        {

        }
    }

    stream << "_" << label << std::endl;

    std::cout << "Exiting jump generation " << std::endl;

    return stream.str();
}

AbstractBasicBlockAssembler * x86BasicBlockAssembler::constructMe(BasicBlock *source) {
    return new x86BasicBlockAssembler(source, false);
}

std::string x86BasicBlockAssembler::getLabelPrefix() {
#ifdef __linux__
    return "";
#elif _WIN32
    return "_";
#else

#endif
}
