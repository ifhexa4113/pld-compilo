//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_ORINSTRUCTION_H
#define PLD_COMPILO_ORINSTRUCTION_H


#include "IRInstruction.h"
#include "Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class OrInstruction : public IRInstruction {
public:
    OrInstruction(Register *destination, Operand *param1, Operand *param2);

    ~OrInstruction() override;

    void print(std::ostream &ost) const override;

    Register *getDestination() const;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Register *destination;
    Operand *param1;
    Operand *param2;
};


#endif //PLD_COMPILO_ORINSTRUCTION_H
