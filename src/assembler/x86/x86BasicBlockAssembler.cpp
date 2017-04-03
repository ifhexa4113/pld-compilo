//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include <map>
#include "x86BasicBlockAssembler.h"


x86BasicBlockAssembler::x86BasicBlockAssembler(BasicBlock *source) : AbstractBasicBlockAssembler(source){
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

std::string x86BasicBlockAssembler::generateProlog() {

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

std::string x86BasicBlockAssembler::translateIR() {
    return "";
}

std::string x86BasicBlockAssembler::generateEpilog() {
    return "";
}
