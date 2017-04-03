//
// Created by Element on 03/04/2017.
//

#ifndef PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
#define PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H

#include "cfg/BasicBlock.h";

/**
 * Transform a basic bloc into assembly
 */
class AbstractBasicBlockAssembler {
public:
    AbstractBasicBlockAssembler(BasicBlock *source);

    std::string translate();
private:
    BasicBlock *source;
};


#endif //PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
