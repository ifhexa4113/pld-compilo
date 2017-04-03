//
// Created by Element on 03/04/2017.
//

#include <sstream>
#include <map>
#include "AbstractBasicBlockAssembler.h"

std::string AbstractBasicBlockAssembler::translate() {
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

    return stream.str();
}

AbstractBasicBlockAssembler::AbstractBasicBlockAssembler(BasicBlock *source) : source(source){
    Table* table = source->getTable();
    std::map<Register *, RegisterInfo> & map = table->getAllRegisters();

    variable_count = map.size();
    int variable_index = 0;

    for(auto pair : map)
    {
        offset_list[pair.first] = variable_index * 4;
        variable_index ++;
    }
}

