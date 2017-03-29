//
// Created by Element on 29/03/2017.
//

#include "JmpInstruction.h"

JmpInstruction::JmpInstruction(std::string label) : IRInstruction(), label(label){

}

JmpInstruction::~JmpInstruction() {

}

void JmpInstruction::print(std::ostream &ost) const {
    ost << "JMP\t" << label << std::endl;
}

const std::string &JmpInstruction::getLabel() const {
    return label;
}
