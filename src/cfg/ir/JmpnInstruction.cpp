//
// Created by Element on 29/03/2017.
//

#include "JmpnInstruction.h"

JmpnInstruction::JmpnInstruction(std::string label) : IRInstruction(), label(label){

}

JmpnInstruction::~JmpnInstruction() {

}

void JmpnInstruction::print(std::ostream &ost) const {
    ost << "JMPN\t" << label << std::endl;
}

const std::string &JmpnInstruction::getLabel() const {
    return label;
}
