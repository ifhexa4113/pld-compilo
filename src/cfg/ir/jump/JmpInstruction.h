//
// Created by Element on 29/03/2017.
//

#ifndef JMPINSTRUCTION_H
#define JMPINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"

class JmpInstruction : public IRInstruction {
public:
    JmpInstruction(std::string label);

    ~JmpInstruction() override;

    void print(std::ostream &ost) const override;

protected:

    std::string label;
public:
    const std::string &getLabel() const;
};


#endif //JMPINSTRUCTION_H
