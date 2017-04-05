#include <iostream>
#include "FunctionDefinition.h"
#include "ast/declaration/FunctionDeclaration.h"
#include "ast/declaration/LValueDeclaration.h"
#include <typeinfo>
#include "ast/ErrorManager.h"

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
    if(stack.checkSymbol(declaration->getName()))
    {
		ErrorManager& errorManager = ErrorManager::getInstance();
		errorManager.addEncounteredError(ErrorManager::SYMBOL_REDECLARATION, declaration->getName());
    }
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
    bool checkReturn = Block::checkReturnType(getType(),stack);
    if (getType()!=Type::VOID_T && !checkReturn)
    {
        ErrorManager& errorManager = ErrorManager::getInstance();
        errorManager.addEncounteredError(ErrorManager::RETURN_MISSING, "");
    }
}

void FunctionDefinition::fillAstTrace(std::string& astTrace)
{
    astTrace += "FUNC DEF\n";
    for (auto child : children)
        child->fillAstTrace(astTrace);
}