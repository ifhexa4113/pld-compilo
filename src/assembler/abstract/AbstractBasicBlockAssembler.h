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

class IRAbstractAssembler;

class AbstractBasicBlockAssembler {
public:
    AbstractBasicBlockAssembler(BasicBlock *source, bool generate_intro = false);

    virtual ~AbstractBasicBlockAssembler();

    virtual std::string generateProlog() = 0;
    virtual std::string translateIR() = 0;
    virtual std::string generateEpilog() = 0;
    virtual std::string getLabel() = 0;
    virtual std::string getIntro() = 0;

    virtual AbstractBasicBlockAssembler * constructMe(BasicBlock *source) = 0;

    virtual std::string getJump(std::string label, BasicBlock::JumpType jumpType) = 0;

    std::string translate();

    int getOffset(Register * reg);

protected:
    BasicBlock *source;
    bool generate_intro;
    Table * table;
    int variable_count;
    int max_argument_count;


};


#endif //PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
