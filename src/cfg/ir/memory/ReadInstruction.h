#ifndef LOADINSTRUCTION_H
#define LOADINSTRUCTION_H

#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Register.h"

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


#endif //LOADINSTRUCTION_H
