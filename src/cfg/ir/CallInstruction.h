//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_CALLINSTRUCTION_H
#define PLD_COMPILO_CALLINSTRUCTION_H


#include "IRInstruction.h"

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


#endif //PLD_COMPILO_JMPINSTRUCTION_H
