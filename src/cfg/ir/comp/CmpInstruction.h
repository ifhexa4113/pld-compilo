//
// Created by Element on 29/03/2017.
//

#ifndef CMPINSTRUCTION_H
#define CMPINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class CmpInstruction : public IRInstruction {
public:
    CmpInstruction(Operand *address, Operand *value);

    ~CmpInstruction() override;

    void print(std::ostream &ost) const override;

    const Operand *getAddress() const;

    const Operand *getValue() const;

protected:
    Operand *address;
    Operand *value;
};


#endif //WRITEINSTRUCTION_H
