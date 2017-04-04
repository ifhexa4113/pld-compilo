//
// Created by Element on 03/04/2017.
//

#ifndef PLD_COMPILO_X86BASICBLOCKASSEMBLER_H
#define PLD_COMPILO_X86BASICBLOCKASSEMBLER_H

#include <assembler/abstract/AbstractBasicBlockAssembler.h>
#include "cfg/BasicBlock.h";

/**
 * Transform a basic bloc into assembly
 */
class x86BasicBlockAssembler : public AbstractBasicBlockAssembler {
public:
    x86BasicBlockAssembler(BasicBlock *source);

    std::string generateProlog();
    std::string translateIR();
    std::string generateEpilog();

    std::string getLabel() override;

    IRAbstractAssembler * translateInstruction(IRInstruction *instruction);
private:
    BasicBlock *source;
};


#endif //PLD_COMPILO_ABSTRACTBASICBLOCKASSEMBLER_H
