//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_MOVX86ASSEMBLER_H
#define PLD_COMPILO_MOVX86ASSEMBLER_H


#include "assembler/x86/operand/Operandx86Assembler.h"
#include "assembler/abstract/basic/MovAbstractAssembler.h"

class Movx86Assembler : public MovAbstractAssembler {
public:
    Movx86Assembler(MovInstruction *instruction);

    ~Movx86Assembler() override;

    std::string translate() const override;

    static std::string getString(Operandx86Assembler source, Operandx86Assembler dest);
};


#endif //PLD_COMPILO_MOVX86ASSEMBLER_H
