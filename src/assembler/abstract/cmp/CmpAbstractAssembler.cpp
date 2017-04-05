//
// Created by Element on 05/04/2017.
//

#include <cfg/ir/comp/CmpInstruction.h>
#include <assembler/abstract/AbstractBasicBlockAssembler.h>
#include <assembler/abstract/IRAbstractAssembler.h>
#include "CmpAbstractAssembler.h"

CmpAbstractAssembler::CmpAbstractAssembler(CmpInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : IRAbstractAssembler(
        parent_block) , instruction(instruction){

}

CmpAbstractAssembler::~CmpAbstractAssembler() {

}
