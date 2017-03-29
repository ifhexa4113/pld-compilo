//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_JMPNINSTRUCTION_H
#define PLD_COMPILO_JMPNINSTRUCTION_H


#include "IRInstruction.h"

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


#endif //PLD_COMPILO_JMPNINSTRUCTION_H
