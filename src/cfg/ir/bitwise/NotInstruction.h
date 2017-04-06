//
// Created by Element on 29/03/2017.
//

#ifndef NOTINSTRUCTION_H
#define NOTINSTRUCTION_H


#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Register.h"

class NotInstruction : public RegisterInstruction {
public:
    NotInstruction(Register *source, Operand *destination);

    ~NotInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getSource() const;

protected:
    Operand *source;
};


#endif //NOTINSTRUCTION_H
