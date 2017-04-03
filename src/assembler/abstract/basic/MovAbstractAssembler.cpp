//
// Created by Element on 02/04/2017.
//

#include "MovAbstractAssembler.h"

MovAbstractAssembler::~MovAbstractAssembler() {

}

MovAbstractAssembler::MovAbstractAssembler(MovInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : IRAbtractAssembler(parent_block), instruction(instruction)
{

}