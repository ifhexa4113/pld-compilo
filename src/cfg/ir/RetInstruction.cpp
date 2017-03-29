//
// Created by Element on 29/03/2017.
//

#include "RetInstruction.h"

RetInstruction::RetInstruction() : IRInstruction() {

}

RetInstruction::~RetInstruction() {

}

void RetInstruction::print(std::ostream &ost) const {
    ost << "RET" << std::endl;
}
