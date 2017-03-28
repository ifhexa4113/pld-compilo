#include <iostream>
#include "FunctionDefinition.h"
#include "ast/declaration/FunctionDeclaration.h"
#include "ast/declaration/LValueDeclaration.h"

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
    std::cout << "Entering function definition \"" << declaration->getName() << "\", exploring block." << std::endl;
    Block::walkTree();
    return 0;
}

void FunctionDefinition::fillSymbolTable(SymbolTableStack& stack)
{
    Definition::fillSymbolTable(stack);
    stack.push(symbolTable);
    if(FunctionDeclaration* functionDeclaration = dynamic_cast<FunctionDeclaration*>(declaration))
    {
        std::vector<LValueDeclaration*>& arguments = functionDeclaration->getArguments();
        for(auto argument : arguments)
        {
            argument->fillSymbolTable(stack);
        }
    }
    Block::fillSymbolTable(stack);
}