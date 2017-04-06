#ifndef ADDINSTRUCTION_H
#define ADDINSTRUCTION_H


#include "cfg/ir/RegisterInstruction.h"
#include "cfg/ir/operand/Register.h"

/**
 * Mnemonic representing a Write value : Store the given value in the given memory address
 */
class AddInstruction : public RegisterInstruction {
public:
    AddInstruction(Register *destination, Operand *param1, Operand *param2);

    ~AddInstruction() override;

    void print(std::ostream &ost) const override;

    Operand *getParam1() const;

    Operand *getParam2() const;

protected:
    Operand *param1;
    Operand *param2;
};


#endif //WRITEINSTRUCTION_H
