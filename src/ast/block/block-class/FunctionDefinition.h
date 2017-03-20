#ifndef FUNCTION_DEFINITION_H
#define FUCNTION_DEFINITION_H

#include <string>

#include "BlockClass.h"

class FunctionDefinition : public BlockClass
{
public:
    FunctionDefinition(std::string name);

    virtual int walkTree();

protected:
    std::string name;
};

#endif