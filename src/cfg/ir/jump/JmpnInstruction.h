//
// Created by Element on 29/03/2017.
//

#ifndef JMPNINSTRUCTION_H
#define JMPNINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"

class JmpnInstruction : public IRInstruction {
public:
    JmpnInstruction(std::string label);

    ~JmpnInstruction() override;

    void print(std::ostream &ost) const override;

protected:

    std::string label;
public:
    const std::string &getLabel() const;
};


#endif //JmpnInstruction_H
