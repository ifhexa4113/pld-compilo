//
// Created by Element on 29/03/2017.
//

#ifndef XORINSTRUCTION_H
#define XORINSTRUCTION_H


#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class XorInstruction : public RegisterInstruction {
public:
    XorInstruction(Register *destination, Operand *param1, Operand *param2);

    ~XorInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Operand *param1;
    Operand *param2;
};


#endif //ORINSTRUCTION_H
