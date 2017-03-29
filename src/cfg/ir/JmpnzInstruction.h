//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_JMPNZINSTRUCTION_H
#define PLD_COMPILO_JMPNZINSTRUCTION_H


#include "IRInstruction.h"

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


#endif //PLD_COMPILO_JMPNZINSTRUCTION_H
