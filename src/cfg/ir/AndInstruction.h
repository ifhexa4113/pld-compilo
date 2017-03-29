//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_ANDINSTRUCTION_H
#define PLD_COMPILO_ANDINSTRUCTION_H


#include "IRInstruction.h"
#include "Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class AndInstruction : public IRInstruction {
public:
    AndInstruction(Register *destination, Operand *param1, Operand *param2);

    ~AndInstruction() override;

    void print(std::ostream &ost) const override;

    Register *getDestination() const;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Register *destination;
    Operand *param1;
    Operand *param2;
};


#endif //PLD_COMPILO_ANDINSTRUCTION_H
