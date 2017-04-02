//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_ADDABSTRACTTRANSLATOR_H
#define PLD_COMPILO_ADDABSTRACTTRANSLATOR_H


#include "assembler/IRAbtractAssembler.h"
#include "cfg/ir/basic/AddInstruction.h"

class AddAbstractAssembler : public IRAbtractAssembler {
public:
    AddAbstractAssembler (AddInstruction * instruction);

    ~AddAbstractAssembler() override;

    virtual std::string translate() const = 0;

protected:
    AddInstruction * instruction;
};


#endif //PLD_COMPILO_ADDABSTRACTTRANSLATOR_H
