//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_DivABSTRACTTRANSLATOR_H
#define PLD_COMPILO_DivABSTRACTTRANSLATOR_H


#include "assembler/abstract/IRAbstractAssembler.h"
#include "cfg/ir/basic/DivInstruction.h"

class DivAbstractAssembler : public IRAbstractAssembler {
public:
    DivAbstractAssembler (DivInstruction * instruction);

    ~DivAbstractAssembler() override;

    virtual std::string translate() const = 0;

protected:
    DivInstruction * instruction;
};


#endif //PLD_COMPILO_DivABSTRACTTRANSLATOR_H
