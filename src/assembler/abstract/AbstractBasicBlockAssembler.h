//
// Created by Element on 03/04/2017.
//

#ifndef PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
#define PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H

#include "cfg/BasicBlock.h"
#include "assembler/abstract/IRAbstractAssembler.h"

/**
 * Transform a basic bloc into assembly
 */
class AbstractBasicBlockAssembler {
public:
    AbstractBasicBlockAssembler(BasicBlock *source);

    virtual std::string generateProlog() = 0;
    virtual std::string translateIR() = 0;
    virtual std::string generateEpilog() = 0;
    virtual std::string getLabel() = 0;

    std::string translate();

    int getOffset(Register * reg);

protected:
    BasicBlock *source;

    std::map<Register *, int> offset_list;
    Table * table;
    int variable_count;
    int max_argument_count;

};


#endif //PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
