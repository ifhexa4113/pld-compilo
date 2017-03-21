#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

#include <string>

#include "BlockClass.h"

class FunctionDefinition : public BlockClass
{
public:
    FunctionDefinition(Block* block_, std::string name_);

    virtual int walkTree();

protected:
    std::string name;
};

#endif