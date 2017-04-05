//
// Created by Element on 29/03/2017.
//

#include "JmpzInstruction.h"

JmpzInstruction::JmpzInstruction(std::string label) : IRInstruction(), label(label){

}

JmpzInstruction::~JmpzInstruction()
{
    // Nothing else to do (the Table handles it)
}

void JmpzInstruction::print(std::ostream &ost) const {
    ost << "JMPZ\t" << label << std::endl;
}

const std::string &JmpzInstruction::getLabel() const {
    return label;
}
