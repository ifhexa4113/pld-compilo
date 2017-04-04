//
// Created by Element on 03/04/2017.
//

#ifndef PLD_COMPILO_CALLX86ASSEMBLER_H
#define PLD_COMPILO_CALLX86ASSEMBLER_H


#include <assembler/abstract/jump/CallAbstractAssembler.h>

class Callx86Assembler : CallAbstractAssembler {
public:
    Callx86Assembler(CallInstruction *instruction, AbstractBasicBlockAssembler *parent_block);

    ~Callx86Assembler() override;

    std::string translate() const override;
};


#endif //PLD_COMPILO_CALLX86ASSEMBLER_H
