#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

#include <string>
#include <vector>
#include "Definition.h"
#include "ast/AstNode.h"
#include "ast/block/Block.h"

class FunctionDefinition : public Definition, public Block
{
public:
    FunctionDefinition(std::string name_);
    FunctionDefinition(std::string name_, std::vector<AstNode*> children_);
    ~FunctionDefinition();
    int walkTree();
};

#endif