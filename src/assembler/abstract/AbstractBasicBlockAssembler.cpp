//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include "AbstractBasicBlockAssembler.h"

std::string AbstractBasicBlockAssembler::translate() {
    return std::__cxx11::string();
}

AbstractBasicBlockAssembler::AbstractBasicBlockAssembler(BasicBlock *source) : source(source){
    std::ostringstream stream;

    if (/* condition generation prologe*/ 1)
    {
        stream << generateProlog();
    }

    stream << translateIR();

    if (1)
    {
        stream << generateEpilog();
    }
}

std::string AbstractBasicBlockAssembler::generateProlog() {

    //
    int variable_count = 0;




    return std::__cxx11::string();
}

std::string AbstractBasicBlockAssembler::translateIR() {
    return std::__cxx11::string();
}

std::string AbstractBasicBlockAssembler::generateEpilog() {
    return std::__cxx11::string();
}
