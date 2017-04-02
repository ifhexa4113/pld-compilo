//
// Created by Element on 29/03/2017.
//

#ifndef RSHIFTINSTRUCTION_H
#define RSHIFTINSTRUCTION_H


#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class RshiftInstruction : public RegisterInstruction {
public:
    RshiftInstruction(Register *destination, Operand *param1, Operand *param2);

    ~RshiftInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Operand *param1;
    Operand *param2;
};


#endif //RSHIFTINSTRUCTION_H
