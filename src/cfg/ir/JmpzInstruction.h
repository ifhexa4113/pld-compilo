//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_JMPZINSTRUCTION_H
#define PLD_COMPILO_JMPZINSTRUCTION_H


#include "IRInstruction.h"

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


#endif //PLD_COMPILO_JMPZINSTRUCTION_H
