//
// Created by Element on 04/04/2017.
//

#ifndef PLD_COMPILO_JUMPABSTRACTASSEMBLER_H
#define PLD_COMPILO_JUMPABSTRACTASSEMBLER_H


#include <assembler/abstract/IRAbstractAssembler.h>

class JmpAbstractAssembler : public IRAbstractAssembler {
public:
    JmpAbstractAssembler(AbstractBasicBlockAssembler *target_block,
                              AbstractBasicBlockAssembler *parent_block);

    ~JmpAbstractAssembler() override;

    std::string translate() const override;

protected:
    AbstractBasicBlockAssembler * target_block;
};


#endif //PLD_COMPILO_JUMPABSTRACTASSEMBLER_H
