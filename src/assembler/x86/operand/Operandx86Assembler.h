//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_OPERANDASSEMBLER_H
#define PLD_COMPILO_OPERANDASSEMBLER_H

#include <cfg/ir/operand/Operand.h>
#include <assembler/abstract/AbstractBasicBlockAssembler.h>

/**
 * Abstract class that allows for the translation between IR operands and Assembler operands
 */
class Operandx86Assembler {
public:
    enum operand_type {
        LITERAL,
        PHYSICAL_REGISTER,
        VIRTUAL_REGISTER,
        WORK_REGISTER
    };

    enum work_register {
        DEST,
        SOURCE
    };

    enum register_type {
        A,
        B,
        C,
        D,
        E,
        SI,
        DI,
        BP
    };

    //static Operandx86Assembler getWorkRegister(work_register id);
    static Operandx86Assembler getVirtualRegister(int offset);
    static Operandx86Assembler getCallRegister(int position);
    static Operandx86Assembler getPhysicalRegister(register_type id);
    operand_type getType() const;

    int getValue() const;


    std::string toString();
    Operandx86Assembler(Operand *operand, AbstractBasicBlockAssembler *parent_block);

    static const uint64_t virtualRegisterMemoryOffset = 0;
    static const int physicalRegisterCount = 4;

protected:
    operand_type type;
    Operandx86Assembler(const operand_type type,const int value);
public:
    void setType(operand_type type);

    void setValue(int value);

protected:
    int value;

};


#endif //PLD_COMPILO_OPERANDASSEMBLER_H
