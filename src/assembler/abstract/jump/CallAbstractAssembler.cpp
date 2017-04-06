//
// Created by Element on 03/04/2017.
//

#include <cfg/ir/jump/CallInstruction.h>
#include <assembler/abstract/AbstractBasicBlockAssembler.h>
#include <assembler/abstract/IRAbstractAssembler.h>
#include "CallAbstractAssembler.h"

CallAbstractAssembler::CallAbstractAssembler(CallInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : IRAbstractAssembler(
        parent_block) , instruction(instruction) {

}

CallAbstractAssembler::~CallAbstractAssembler() {

}

std::string CallAbstractAssembler::translate() const {
    return nullptr;
}
