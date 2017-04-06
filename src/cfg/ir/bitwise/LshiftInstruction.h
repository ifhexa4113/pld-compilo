//
// Created by Element on 29/03/2017.
//

#ifndef LSHIFTINSTRUCTION_H
#define LSHIFTINSTRUCTION_H


#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class LshiftInstruction : public RegisterInstruction {
public:
    LshiftInstruction(Register *destination, Operand *param1, Operand *param2);

    ~LshiftInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Operand *param1;
    Operand *param2;
};


#endif //LSHIFTINSTRUCTION_H
