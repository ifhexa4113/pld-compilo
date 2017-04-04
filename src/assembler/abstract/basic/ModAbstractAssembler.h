//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_ModABSTRACTTRANSLATOR_H
#define PLD_COMPILO_ModABSTRACTTRANSLATOR_H


#include "assembler/abstract/IRAbstractAssembler.h"
#include "cfg/ir/basic/ModInstruction.h"

class ModAbstractAssembler : public IRAbstractAssembler {
public:
    ModAbstractAssembler (ModInstruction * instruction);

    ~ModAbstractAssembler() override;

    virtual std::string translate() const = 0;

protected:
    ModInstruction * instruction;
};


#endif //PLD_COMPILO_ModABSTRACTTRANSLATOR_H
