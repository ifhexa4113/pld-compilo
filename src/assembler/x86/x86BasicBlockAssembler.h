//
// Created by Element on 03/04/2017.
//

#ifndef PLD_COMPILO_X86BASICBLOCKASSEMBLER_H
#define PLD_COMPILO_X86BASICBLOCKASSEMBLER_H

#include <assembler/abstract/AbstractBasicBlockAssembler.h>
#include "cfg/BasicBlock.h"

/**
 * Transform a basic bloc into assembly
 */
class x86BasicBlockAssembler : public AbstractBasicBlockAssembler {
public:
    x86BasicBlockAssembler(BasicBlock *source, bool generate_intro);

    std::string generateProlog() override ;
    std::string translateIR();
    std::string generateEpilog() override ;

    std::string getLabel() override;

    std::string getIntro() override;

    std::string getJump(std::string label, BasicBlock::JumpType jumpType) override;

    AbstractBasicBlockAssembler * constructMe(BasicBlock *source) override;

    IRAbstractAssembler * translateInstruction(IRInstruction *instruction);
};


#endif //PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
