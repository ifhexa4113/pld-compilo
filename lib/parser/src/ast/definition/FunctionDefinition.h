#ifndef FUNCTION_DEFINITION_H
#define FUNCTION_DEFINITION_H

#include <vector>
#include "Definition.h"
#include "ast/AstNode.h"
#include "ast/block/Block.h"
#include "ast/declaration/FunctionDeclaration.h"

class FunctionDefinition : public Definition, public Block
{
public:
    FunctionDefinition(FunctionDeclaration* declaration_);
    FunctionDefinition(FunctionDeclaration* declaration_, std::vector<AstNode*> children_);
    ~FunctionDefinition();
    int walkTree();
};

#endif