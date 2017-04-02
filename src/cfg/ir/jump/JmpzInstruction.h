//
// Created by Element on 29/03/2017.
//

#ifndef JMPZINSTRUCTION_H
#define JMPZINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"

class JmpzInstruction : public IRInstruction {
public:
    JmpzInstruction(std::string label);

    ~JmpzInstruction() override;

    void print(std::ostream &ost) const override;

protected:

    std::string label;
public:
    const std::string &getLabel() const;
};


#endif //JMPZINSTRUCTION_H
