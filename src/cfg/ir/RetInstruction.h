//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_RETINSTRUCTION_IR_H
#define PLD_COMPILO_RETINSTRUCTION_IR_H


#include "IRInstruction.h"

class RetInstruction : public IRInstruction{
public:
    RetInstruction();

    ~RetInstruction() override;

    void print(std::ostream &ost) const override;
};


#endif //PLD_COMPILO_RETINSTRUCTION_H
