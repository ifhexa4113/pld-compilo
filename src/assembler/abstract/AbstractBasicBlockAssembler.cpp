//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include <map>
#include "AbstractBasicBlockAssembler.h"

std::string AbstractBasicBlockAssembler::translate() {
    return std::__cxx11::string();
}

AbstractBasicBlockAssembler::AbstractBasicBlockAssembler(BasicBlock *source) : source(source){
    std::ostringstream stream;

    if (source->isPrologable())
    {
        stream << generateProlog();
    }

    stream << translateIR();

    if (source->isPrologable())
    {
        stream << generateEpilog();
    }
}

std::string AbstractBasicBlockAssembler::generateProlog() {

    Table* table = source->getTable();
    std::map<Register *, RegisterInfo> & map = table->getAllRegisters();


    int variable_count = map.size();
    int variable_index = 0;

    for(auto pair : map)
    {
        pair.second.setOffset(variable_index * 4);
        variable_index ++;
    }

    std::ostringstream stream;

    // pushl %epb
    // movl %esp, %epb
    // subl $variable_count * 4, %esp

    // PAS LE TEMPS DE NIAISER
    stream << "pushl %epb" << std::endl;
    stream << "movl %esp, %epb" << std::endl;
    stream << "subl " << variable_count * 4 << ", %esp" << std::endl;




    return stream.str();
}

std::string AbstractBasicBlockAssembler::translateIR() {
    return std::__cxx11::string();
}

std::string AbstractBasicBlockAssembler::generateEpilog() {
    return std::__cxx11::string();
}
