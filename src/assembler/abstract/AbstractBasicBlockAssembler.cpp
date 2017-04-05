//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include <map>
#include <cfg/ir/jump/CallInstruction.h>
#include <assembler/x86/jump/Callx86Assembler.h>
#include <iostream>
#include "AbstractBasicBlockAssembler.h"

std::string AbstractBasicBlockAssembler::translate() {
    std::ostringstream stream;
    std::cout << "Generating asm " << variable_count << std::endl;

    stream << "# TRANSLATING << " << source->getLabel() <<  "\n\n";

    std::cout << "INTRO" << std::endl;

    if (generate_intro)
    {
        stream << getIntro();
    }
    std::cout << "LABEL" << std::endl;

    stream << getLabel();

    std::cout << "PROLOG" << std::endl;


    if (source->isPrologable())
    {
        stream << generateProlog();
    }

    std::cout << "IR" << std::endl;

    stream << translateIR();

    BasicBlock * exit_true = source->getExitTrue();
    BasicBlock * exit_false = source->getExitFalse();

    std::cout << "Before jumps" << std::endl;;
    if ((exit_true) != nullptr)
    {
        if ((exit_false) != nullptr)
        {
            stream << getJump(exit_true->getLabel(), exit_true->getExitJumpType());
            stream << getJump(exit_false->getLabel(), BasicBlock::JumpType::NUL);
        }
        else
        {
            stream << getJump(exit_true->getLabel(), BasicBlock::JumpType::NUL);
        }
    }
    else
    {
        stream << generateEpilog();
    }

    if (exit_true != nullptr)
    {
        if (!exit_true->isColored())
        {
            AbstractBasicBlockAssembler * abba_true = constructMe(exit_true);
            std::cout << "# GENERATING TRUE OUTPUT \n\n";
            stream << abba_true->translate();
            exit_true->setColored(true);

            delete abba_true;
        }




        if (exit_false != nullptr)
        {
            if (!exit_false->isColored())
            {
                AbstractBasicBlockAssembler * abba_false = constructMe(exit_false);
                stream << "# GENERATING FALSE OUTPUT \n\n";
                stream << abba_false->translate();
                exit_false->setColored(true);
                delete abba_false;
            }

        }
    }

    return stream.str();
}

AbstractBasicBlockAssembler::AbstractBasicBlockAssembler(BasicBlock *source, bool generate_intro)
        : source(source), generate_intro(generate_intro), variable_count(-1){
    std::cout << "Prout " << source->getLabel();

    Table* table = source->getTable();
    auto map = table->getAllRegisters();
    auto it = map->begin();
    int variable_index = 1;
    max_argument_count = 0;

    for(IRInstruction * intr : source->getInstructions())
    {
        // do cast and stuff
        CallInstruction * cast = dynamic_cast<CallInstruction *>(intr);
        if (cast != nullptr)
        {
            int args = cast->getRegisters().size();
            if (max_argument_count < args)
            {
                max_argument_count = args;
            }
        }
    }
    variable_index += max_argument_count;

    while (it != map->end()) {
        it->second.setOffset(variable_index * 4);
        variable_index++;
        it++;
    }
    variable_count = variable_index;
    std::cout << variable_count << std::endl;
}

int AbstractBasicBlockAssembler::getOffset(Register *reg) {
    return source->getTable()->getRegisterInfo(reg).getOffset();
}

AbstractBasicBlockAssembler::~AbstractBasicBlockAssembler() {

}

