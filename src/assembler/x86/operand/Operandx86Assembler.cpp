//
// Created by Element on 02/04/2017.
//

#include <cfg/ir/operand/Register.h>
#include "cfg/ir/operand/LiteralNumber.h"
#include "Operandx86Assembler.h"
#include <string>
#include <sstream>
#include <assembler/abstract/AbstractBasicBlockAssembler.h>
#include <iostream>

Operandx86Assembler::Operandx86Assembler(Operand *operand, AbstractBasicBlockAssembler *parent_block) {
    LiteralNumber *lit = nullptr;
    Register *reg = nullptr;

    if ((lit = dynamic_cast<LiteralNumber*>(operand)) != nullptr)
    {
        value = lit->getValue();
        type = operand_type::LITERAL;
    }
    else if ((reg = dynamic_cast<Register*>(operand)) != nullptr)
    {
        value = parent_block->getOffset((Register*) operand);
        type = operand_type::VIRTUAL_REGISTER;
    }
}

std::string Operandx86Assembler::toString() {
    std::ostringstream stm ;

    switch (type) {
        case operand_type::LITERAL : {
            stm << "$" << value;
            break;
        }
        case operand_type::PHYSICAL_REGISTER : {
            break;
        }
        case operand_type::VIRTUAL_REGISTER : {
            stm << -value << "(%esp)";
        }
        default:
            break;

    }

    return stm.str();
}

Operandx86Assembler::operand_type Operandx86Assembler::getType() const {
    return type;
}

int Operandx86Assembler::getValue() const {
    return value;
}

/*Operandx86Assembler Operandx86Assembler::getWorkRegister(Operandx86Assembler::work_register id) {
    return Operandx86Assembler(Operandx86Assembler::operand_type::WORK_REGISTER, id);
}*/

void Operandx86Assembler::setType(Operandx86Assembler::operand_type type) {
    Operandx86Assembler::type = type;
}

void Operandx86Assembler::setValue(int value) {
    Operandx86Assembler::value = value;
}

Operandx86Assembler::Operandx86Assembler(const Operandx86Assembler::operand_type type, const int value) : type(type), value(value) {

}

Operandx86Assembler Operandx86Assembler::getVirtualRegister(int offset) {
    Operandx86Assembler op(nullptr, nullptr);
    op.value = offset;
    op.type = operand_type::VIRTUAL_REGISTER;
}
