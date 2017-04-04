//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_ADDABSTRACTTRANSLATOR_H
#define PLD_COMPILO_ADDABSTRACTTRANSLATOR_H


#include "assembler/abstract/IRAbstractAssembler.h"
#include "cfg/ir/basic/AddInstruction.h"

class AddAbstractAssembler : public IRAbstractAssembler {
public:
    AddAbstractAssembler(AddInstruction *instruction, AbstractBasicBlockAssembler *parent_block);

    virtual ~AddAbstractAssembler() override;

    virtual std::string translate() const = 0;

protected:
    AddInstruction * instruction;
};


#endif //PLD_COMPILO_ADDABSTRACTTRANSLATOR_H
