//
// Created by Element on 29/03/2017.
//

#include "NotInstruction.h"

NotInstruction::NotInstruction(Register *destination, Operand *source) : IRInstruction(), destination(destination), source(source){

}

NotInstruction::~NotInstruction() {
    delete destination;
    delete source;
}

void NotInstruction::print(std::ostream &ost) const {
    ost << "NOT\t" << destination << ", " << source << std::endl;
}

Register *NotInstruction::getDestination() const {
    return destination;
}

Operand *NotInstruction::getSource() const {
    return source;
}
