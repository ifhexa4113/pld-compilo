//
// Created by Element on 03/04/2017.
//

#ifndef PLD_COMPILO_CALLABSTRACTASSEMBLER_H
#define PLD_COMPILO_CALLABSTRACTASSEMBLER_H


#include <assembler/abstract/IRAbstractAssembler.h>
#include <cfg/ir/jump/CallInstruction.h>

class CallAbstractAssembler : public IRAbstractAssembler {
public:
    CallAbstractAssembler(CallInstruction *instruction, AbstractBasicBlockAssembler *parent_block);

    ~CallAbstractAssembler() override;

    std::string translate() const override;

protected:
    CallInstruction * instruction;
};


#endif //PLD_COMPILO_CALLABSTRACTASSEMBLER_H
