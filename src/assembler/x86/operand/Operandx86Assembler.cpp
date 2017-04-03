//
// Created by Element on 02/04/2017.
//

#include <cfg/ir/operand/Register.h>
#include "cfg/ir/operand/LiteralNumber.h"
#include "Operandx86Assembler.h"
#include <string>
#include <sstream>
#include <assembler/abstract/AbstractBasicBlockAssembler.h>

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
        // plz kill me :(

        //int tmp_value = std::stoi(reg->getName().substr(4,2), nullptr, 0);
        // Check if we can map
        if (reg->getValue() <= physicalRegisterCount)
        {
            //value = reg->getValue();
            type = operand_type::PHYSICAL_REGISTER;
        }
        else
        {
            //value = reg->getValue() - physicalRegisterCount;
            type = operand_type::VIRTUAL_REGISTER;
        }
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
            switch (value) {
                case 1:
                    stm << "eax";
                    break;
                case 2:
                    stm << "ecx";
                    break;
                case 3:
                    stm << "edx";
                    break;
                case 4:
                    stm << "ebx";
                    break;
                /*case 5:
                    stm << "esi";
                    break;
                case 6:
                    stm << "edi";
                    break;*/
                default:
                    break;

            }
        }
        case operand_type::VIRTUAL_REGISTER : {
            /*stm << "[" << Operandx86Assembler::virtualRegisterMemoryOffset + (value - Operandx86Assembler::physicalRegisterCount) *
                                                                                     sizeof(uint64_t) << "]";*/
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
