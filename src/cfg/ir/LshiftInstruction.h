//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_LSHIFTINSTRUCTION_H
#define PLD_COMPILO_LSHIFTINSTRUCTION_H


#include "IRInstruction.h"
#include "Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class LshiftInstruction : public IRInstruction {
public:
    LshiftInstruction(Register *destination, Operand *param1, Operand *param2);

    ~LshiftInstruction() override;

    void print(std::ostream &ost) const override;

    Register *getDestination() const;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Register *destination;
    Operand *param1;
    Operand *param2;
};


#endif //PLD_COMPILO_LSHIFTINSTRUCTION_H
