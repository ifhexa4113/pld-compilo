//
// Created by Element on 29/03/2017.
//

#ifndef CMPINSTRUCTION_H
#define CMPINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class CmpInstruction : public IRInstruction {
public:
    CmpInstruction(Operand *param1_, Operand *param2_);

    ~CmpInstruction() override;

    void print(std::ostream &ost) const override;

    Operand * getParam1() const;

    Operand * getParam2() const;

protected:
    Operand *param1;
    Operand *param2;
};


#endif //WRITEINSTRUCTION_H
