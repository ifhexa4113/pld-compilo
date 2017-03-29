//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_MULINSTRUCTION_H
#define PLD_COMPILO_MULINSTRUCTION_H


#include "RegisterInstruction.h"
#include "Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class MulInstruction : public RegisterInstruction {
public:
    MulInstruction(Register *destination, Operand *param1, Operand *param2);

    ~MulInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Operand *param1;
    Operand *param2;
};


#endif //PLD_COMPILO_MULINSTRUCTION_H
