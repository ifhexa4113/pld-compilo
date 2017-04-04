//
// Created by Element on 02/04/2017.
//

#include "AddAbstractAssembler.h"

AddAbstractAssembler::~AddAbstractAssembler() {

}

AddAbstractAssembler::AddAbstractAssembler(AddInstruction *instruction, AbstractBasicBlockAssembler *parent_block)
        : IRAbstractAssembler(parent_block), instruction(instruction){

}
