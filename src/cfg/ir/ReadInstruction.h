//
// Created by Element on 29/03/2017.
//

#ifndef PROJECT_LOADINSTRUCTION_H
#define PROJECT_LOADINSTRUCTION_H

#include "IRInstruction.h"
#include "Register.h"

/**
 * Mnemonic representing a Read Operation : Get a value from the given address and store it in the given register.
 */
class ReadInstruction : public RegisterInstruction {
public:
    ReadInstruction(Register *destination, Operand *address);

    ~ReadInstruction() override;

    void print(std::ostream &ost) const override;

    const Operand *getAddress() const;

protected:
    Operand *address;
};


#endif //PROJECT_LOADINSTRUCTION_H
