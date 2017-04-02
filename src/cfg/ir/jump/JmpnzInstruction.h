//
// Created by Element on 29/03/2017.
//

#ifndef JMPNZINSTRUCTION_H
#define JMPNZINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"

class JmpnzInstruction : public IRInstruction {
public:
    JmpnzInstruction(std::string label);

    ~JmpnzInstruction() override;

    void print(std::ostream &ost) const override;

protected:

    std::string label;
public:
    const std::string &getLabel() const;
};


#endif //JMPNZINSTRUCTION_H
