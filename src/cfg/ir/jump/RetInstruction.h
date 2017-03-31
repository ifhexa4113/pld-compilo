//
// Created by Element on 29/03/2017.
//

#ifndef RETINSTRUCTION_IR_H
#define RETINSTRUCTION_IR_H


#include "cfg/ir/IRInstruction.h"

class RetInstruction : public IRInstruction{
public:
    RetInstruction();

    ~RetInstruction() override;

    void print(std::ostream &ost) const override;
};


#endif //RETINSTRUCTION_H
