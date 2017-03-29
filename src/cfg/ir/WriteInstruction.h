//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_WRITEINSTRUCTION_H
#define PLD_COMPILO_WRITEINSTRUCTION_H


#include "IRInstruction.h"
#include "Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class WriteInstruction : public IRInstruction {
public:
    WriteInstruction(Operand address, Operand value);

    ~WriteInstruction() override;

    void print(std::ostream &ost) const override;

    const Operand &getAddress() const;

    const Operand &getValue() const;

protected:
    Operand address;
    Operand value;
};


#endif //PLD_COMPILO_WRITEINSTRUCTION_H
