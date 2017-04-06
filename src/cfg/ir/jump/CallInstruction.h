//
// Created by Element on 29/03/2017.
//

#ifndef CALLINSTRUCTION_H
#define CALLINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"
#include "cfg/ir/operand/Register.h"
#include <vector>

class CallInstruction : public IRInstruction {
public:
    CallInstruction(std::string label_, std::vector<Register*> registers_);

    ~CallInstruction() override;

    std::vector<Register*>& getRegisters();

    void print(std::ostream &ost) const override;

protected:
    std::string label;
    std::vector<Register*> registers;
public:
    const std::string &getLabel() const;
};


#endif //JMPINSTRUCTION_H
