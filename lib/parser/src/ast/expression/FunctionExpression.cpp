#include <iostream>
#include "FunctionExpression.h"
#include "ast/declaration/FunctionDeclaration.h"

#include "ast/declaration/Declaration.h"
#include "ast/ErrorManager.h"

FunctionExpression::FunctionExpression(std::string name_) :
    FunctionExpression(name_, std::vector<Expression*>())
{
    // Nothing else to do
}

FunctionExpression::FunctionExpression(std::string name_, std::vector<Expression*> parameters_) :
    Expression(),
    name(name_),
    parameters(parameters_)
{
    // Nothing else to do
}

FunctionExpression::~FunctionExpression()
{
    for(auto expression : parameters)
    {
        delete expression;
    }
}

int FunctionExpression::walkTree()
{
    std::cout << "Calling function " << name << " with following parameters: ";
    for(auto param : parameters)
    {
        param->walkTree();
        std::cout << ", ";
    }
    std::cout << std::endl;
    return 0;
}

std::string FunctionExpression::getName()
{
    return name;
}

std::vector<Expression *> FunctionExpression::getParameters()
{
    return parameters;
}

Type FunctionExpression::getType(SymbolTableStack& stack)
{
    
    return (stack.getSymbol(name))->getType();

}

void FunctionExpression::fillSymbolTable(SymbolTableStack& stack)
{
    if(!stack.checkSymbol(name))
    {
		ErrorManager& errorManager = ErrorManager::getInstance();
		errorManager.addEncounteredError(ErrorManager::UNKNOWN_FUNCTION_SYMBOL, name);
    }

    // TODO stack.getSymbol can be null ?
    if(FunctionDeclaration* functionDeclaration = dynamic_cast<FunctionDeclaration*>(stack.getSymbol(name)))
    {
        if(static_cast<int>(parameters.size()) != functionDeclaration->getNbArgs())
        {
			ErrorManager& errorManager = ErrorManager::getInstance();
			errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_ARGUMENTS_NUMBER, name);
        }
    }

    for(auto parameter : parameters)
        parameter->fillSymbolTable(stack);
}