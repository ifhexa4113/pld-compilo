//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_NOTINSTRUCTION_H
#define PLD_COMPILO_NOTINSTRUCTION_H


#include "IRInstruction.h"
#include "Register.h"

class NotInstruction : public IRInstruction {
public:
    NotInstruction(Register *source, Operand *destination);

    ~NotInstruction() override;

    void print(std::ostream &ost) const override;
protected:
    Register *destination;
public:
    Register *getDestination() const;

    Operand *getSource() const;

protected:
    Operand  *source;
};


#endif //PLD_COMPILO_NOTINSTRUCTION_H
