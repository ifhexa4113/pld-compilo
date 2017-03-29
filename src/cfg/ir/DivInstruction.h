//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_DIVINSTRUCTION_H
#define PLD_COMPILO_DIVINSTRUCTION_H


#include "IRInstruction.h"
#include "Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class DivInstruction : public IRInstruction {
public:
    DivInstruction(Register *destination, Operand *param1, Operand *param2);

    ~DivInstruction() override;

    void print(std::ostream &ost) const override;

    Register *getDestination() const;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Register *destination;
    Operand *param1;
    Operand *param2;
};


#endif //PLD_COMPILO_MULINSTRUCTION_H
