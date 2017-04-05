//
// Created by Element on 05/04/2017.
//

#ifndef PLD_COMPILO_CMPX86ASSEMBLER_H
#define PLD_COMPILO_CMPX86ASSEMBLER_H


#include <assembler/abstract/cmp/CmpAbstractAssembler.h>

class Cmpx86Assembler : public CmpAbstractAssembler {
public:
    Cmpx86Assembler(CmpInstruction *instruction, AbstractBasicBlockAssembler *parent_block);

    ~Cmpx86Assembler() override;

    std::string translate() const override;
};


#endif //PLD_COMPILO_CMPX86ASSEMBLER_H
