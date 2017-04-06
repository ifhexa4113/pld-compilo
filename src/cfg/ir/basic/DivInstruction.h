//
// Created by Element on 29/03/2017.
//

#ifndef DIVINSTRUCTION_H
#define DIVINSTRUCTION_H


#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class DivInstruction : public RegisterInstruction {
public:
    DivInstruction(Register *destination, Operand *param1, Operand *param2);

    ~DivInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Operand *param1;
    Operand *param2;
};


#endif //MULINSTRUCTION_H
