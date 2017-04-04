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

    if (generate_intro)
    {
        stream << getIntro();
    }

    stream << getLabel();

    if (source->isPrologable())
    {
        stream << generateProlog();
    }

    stream << translateIR();

    if (source->isPrologable())
    {
        stream << generateEpilog();
    }

    return stream.str();
}

AbstractBasicBlockAssembler::AbstractBasicBlockAssembler(BasicBlock *source, bool generate_intro)
        : source(source), generate_intro(generate_intro), offset_list(){
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

    while (it != map->end())
    {
        it->second.setOffset(variable_index * 4);
        variable_index ++;
        it ++;
    }
    variable_count = variable_index;
}

int AbstractBasicBlockAssembler::getOffset(Register *reg) {
    return source->getTable()->getRegisterInfo(reg).getOffset();
}

