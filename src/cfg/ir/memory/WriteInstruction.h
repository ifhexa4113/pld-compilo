#ifndef WRITEINSTRUCTION_H
#define WRITEINSTRUCTION_H


#include "cfg/ir/IRInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class WriteInstruction : public IRInstruction {
public:
    WriteInstruction(Operand *address, Operand *value);

    ~WriteInstruction() override;

    void print(std::ostream &ost) const override;

    const Operand *getAddress() const;

    const Operand *getValue() const;

protected:
    Operand *address;
    Operand *value;
};


#endif //WRITEINSTRUCTION_H
