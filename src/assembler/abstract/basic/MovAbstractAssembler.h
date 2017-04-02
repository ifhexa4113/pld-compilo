//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_MovABSTRACTTRANSLATOR_H
#define PLD_COMPILO_MovABSTRACTTRANSLATOR_H


#include "assembler/IRAbtractAssembler.h"
#include "cfg/ir/basic/MovInstruction.h"

class MovAbstractAssembler : public IRAbtractAssembler {
public:
    MovAbstractAssembler (MovInstruction * instruction);

    ~MovAbstractAssembler() override;

    virtual std::string translate() const = 0;

protected:
    MovInstruction * instruction;
};


#endif //PLD_COMPILO_MovABSTRACTTRANSLATOR_H
