//
// Created by Element on 29/03/2017.
//

#include "JmpnzInstruction.h"

JmpnzInstruction::JmpnzInstruction(std::string label) : IRInstruction(), label(label){

}

JmpnzInstruction::~JmpnzInstruction() {

}

void JmpnzInstruction::print(std::ostream &ost) const {
    ost << "JMPNZ\t" << label << std::endl;
}

const std::string &JmpnzInstruction::getLabel() const {
    return label;
}
