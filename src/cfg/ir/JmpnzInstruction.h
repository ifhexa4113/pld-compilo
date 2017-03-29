//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_JMPINSTRUCTION_H
#define PLD_COMPILO_JMPINSTRUCTION_H


#include "IRInstruction.h"

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


#endif //PLD_COMPILO_JMPINSTRUCTION_H
