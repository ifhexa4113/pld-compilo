//
// Created by Element on 29/03/2017.
//

#include "CallInstruction.h"

CallInstruction::CallInstruction(std::string label) : IRInstruction(), label(label){

}

CallInstruction::~CallInstruction() {

}

void CallInstruction::print(std::ostream &ost) const {
    ost << "CALL\t" << label << std::endl;
}

const std::string &CallInstruction::getLabel() const {
    return label;
}
