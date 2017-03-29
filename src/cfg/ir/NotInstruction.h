//
// Created by Element on 29/03/2017.
//

#ifndef PLD_COMPILO_NOTINSTRUCTION_H
#define PLD_COMPILO_NOTINSTRUCTION_H


#include "RegisterInstruction.h"
#include "Register.h"

class NotInstruction : public RegisterInstruction {
public:
    NotInstruction(Register *source, Operand *destination);

    ~NotInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getSource() const;

protected:
    Operand  *source;
};


#endif //PLD_COMPILO_NOTINSTRUCTION_H
