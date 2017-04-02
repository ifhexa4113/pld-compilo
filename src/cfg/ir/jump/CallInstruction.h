//
// Created by Element on 29/03/2017.
//

#ifndef CALLINSTRUCTION_H
#define CALLINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"

class CallInstruction : public IRInstruction {
public:
    CallInstruction(std::string label);

    ~CallInstruction() override;

    void print(std::ostream &ost) const override;

protected:

    std::string label;
public:
    const std::string &getLabel() const;
};


#endif //JMPINSTRUCTION_H
