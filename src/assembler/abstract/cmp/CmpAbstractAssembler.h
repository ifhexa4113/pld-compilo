//
// Created by Element on 05/04/2017.
//

#ifndef PLD_COMPILO_CMPABSTRACTASSEMBLER_H
#define PLD_COMPILO_CMPABSTRACTASSEMBLER_H


#include <assembler/abstract/IRAbstractAssembler.h>
#include <cfg/ir/comp/CmpInstruction.h>

class CmpAbstractAssembler : public IRAbstractAssembler {
public:
    CmpAbstractAssembler(CmpInstruction *instruction, AbstractBasicBlockAssembler *parent_block);

    virtual ~CmpAbstractAssembler() override;

    virtual std::string translate() const = 0;

protected:
    CmpInstruction * instruction;
};


#endif //PLD_COMPILO_CMPABSTRACTASSEMBLER_H
