//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_ADDX86ASSEMBLER_H
#define PLD_COMPILO_ADDX86ASSEMBLER_H


#include <assembler/abstract/basic/AddAbstractAssembler.h>

class Addx86Assembler : AddAbstractAssembler {
public:
    Addx86Assembler(AddInstruction *instruction);

    std::string translate() const override;
private:

    ~Addx86Assembler() override;

};


#endif //PLD_COMPILO_ADDX86ASSEMBLER_H
