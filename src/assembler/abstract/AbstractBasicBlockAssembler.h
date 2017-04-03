//
// Created by Element on 03/04/2017.
//

#ifndef PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
#define PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H

#include "cfg/BasicBlock.h"

/**
 * Transform a basic bloc into assembly
 */
class AbstractBasicBlockAssembler {
public:
    AbstractBasicBlockAssembler(BasicBlock *source);

    virtual std::string generateProlog() = 0;
    virtual std::string translateIR() = 0;
    virtual std::string generateEpilog() = 0;

    std::string translate();
protected:
    BasicBlock *source;

    std::map<Register *, int> offset_list;
    Table * table;
    int variable_count;

};


#endif //PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
