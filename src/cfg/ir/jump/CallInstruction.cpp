//
// Created by Element on 29/03/2017.
//

#include "CallInstruction.h"

CallInstruction::CallInstruction(std::string label_, std::vector<Register*> registers_) :
  IRInstruction(),
  label(label_),
  registers(registers_){

}

CallInstruction::~CallInstruction() {

}

void CallInstruction::print(std::ostream &ost) const {
    ost << "CALL\t" << label;
    for(auto param: registers)
    {
        ost << "\t" << *param;
    }
    ost <<std::endl;
}

const std::string &CallInstruction::getLabel() const {
    return label;
}

std::vector<Register*>& CallInstruction::getRegisters(){
    return registers;
}
