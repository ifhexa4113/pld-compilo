//
// Created by Element on 04/04/2017.
//

#include "JmpAbstractAssembler.h"
#include <sstream>

JmpAbstractAssembler::JmpAbstractAssembler(AbstractBasicBlockAssembler *target_block,
                                             AbstractBasicBlockAssembler *parent_block) : IRAbstractAssembler(
        parent_block), target_block(target_block) {

}

JmpAbstractAssembler::~JmpAbstractAssembler() {

}

std::string JmpAbstractAssembler::translate() const {
    std::ostringstream stream;

    stream << "\tjmp\t" << target_block->getLabel() << std::endl;

    return stream.str();
}
