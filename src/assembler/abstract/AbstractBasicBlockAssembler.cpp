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
    stream << "# TRANSLATING << " << source->getLabel() <<  "\n\n";
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

    BasicBlock * exit_true = source->getExitTrue();
    BasicBlock * exit_false = source->getExitFalse();

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
    else if ((exit_false) == nullptr)
    {
        stream << generateEpilog();
    }
    else
    {
        // Edge case : while without bloc
        stream << getJump(exit_false->getLabel(), exit_false->getExitJumpType());
        stream << generateEpilog();

        //std::cout << "###### ERROR : A BASIC BLOCK HAS A FALSE OUTPUT BUT NOT A TRUE ONE #######" << std::endl;
    }


    if (exit_true != nullptr) {
        if (!exit_true->isColored()) {
            //std::cout << "Generating exit_true" << std::endl;

            /*if (exit_true->getTable() == nullptr)
            {
                std::cout << "No table detected, assigning current table" << std::endl;
                exit_true->setTable(table);
            }*/
            exit_true->setColored(true);

            AbstractBasicBlockAssembler *abba_true = constructMe(exit_true);
            stream << "\n# GENERATING TRUE OUTPUT for " << getLabel() << "\n";
            stream << abba_true->translate();

            delete abba_true;
        } else {
        }
    }

    if (exit_false != nullptr)
    {
        if (!exit_false->isColored())
        {
            /*if (exit_false->getTable() == nullptr)
            {
                exit_false->setTable(table);
            }*/
            exit_false->setColored(true);

            AbstractBasicBlockAssembler * abba_false = constructMe(exit_false);
            stream << "\n# GENERATING FALSE OUTPUT for " << getLabel() << "\n";
            stream << abba_false->translate();
            delete abba_false;
        }
        else
        {
            std::cout << exit_false->getLabel() << " is colored, skipping ..." << std::endl;
        }

    }

    return stream.str();
}

AbstractBasicBlockAssembler::AbstractBasicBlockAssembler(BasicBlock *source, bool generate_intro)
        : source(source), generate_intro(generate_intro), variable_count(-1){
    //std::cout << "Constructor ABBA for " << source->getLabel() << std::endl;

    Table* table = source->getTable();

    if (generate_intro)
    {
        int variable_index = 1;
        max_argument_count = 0;



        //std::cout << "Getting instruction" << std::endl;

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
        //std::cout << "Got instructions" << std::endl;
        auto map = table->getAllRegisters();
        std::map<Register *, RegisterInfo >::iterator it = map->begin();
        while (map != nullptr && it != map->end()) {
            //std::cout << "..." << std::endl;
            it->second.setOffset(variable_index * 4);
            variable_index++;
            it++;
        }
        variable_count = variable_index;
        //std::cout << variable_count << std::endl;
    } else
    {
        //std::cout << "Skiping table generation" << std::endl;
    }

    //std::cout << "Quiting constructor" << std::endl;
}

int AbstractBasicBlockAssembler::getOffset(Register *reg) {
    return source->getTable()->getRegisterInfo(reg).getOffset();
}

AbstractBasicBlockAssembler::~AbstractBasicBlockAssembler() {

}

