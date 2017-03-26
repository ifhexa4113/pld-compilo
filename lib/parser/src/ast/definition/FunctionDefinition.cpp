#include <iostream>
#include "FunctionDefinition.h"
#include "ast/declaration/FunctionDeclaration.h"

FunctionDefinition::FunctionDefinition(FunctionDeclaration* declaration_) :
    Definition(declaration_),
    Block()
{
    // Nothing else to do
}

FunctionDefinition::FunctionDefinition(FunctionDeclaration* declaration_, std::vector<AstNode *> children_) :
    Definition(declaration_),
    Block(children_)
{
    // Nothing else to do
}

FunctionDefinition::~FunctionDefinition()
{
    // Nothing else to do
}

int FunctionDefinition::walkTree()
{
    std::cout << "Entering function definition \"" << name << "\", exploring block." << std::endl;
    Block::walkTree();
    return 0;
}