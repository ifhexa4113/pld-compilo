#include "For.h"
#include "ast/expression/NullExpression.h"
#include <iostream>
#include <typeinfo>
#include "ast/expression/FunctionExpression.h"
#include "ast/ErrorManager.h"

For::For(Expression* condition_, AstNode* initialization_, Expression* increment_) :
    ConditionalStructure(condition_),
    initialization(initialization_),
    increment(increment_)
{
    if(initialization == nullptr)
    {
        initialization = new NullExpression();
    }
    if(increment == nullptr)
    {
        increment = new NullExpression();
    }
}

For::For(Expression *condition_, AstNode *initialization_, Expression *increment_, std::vector<AstNode *> children_) :
    ConditionalStructure(condition_, children_),
    initialization(initialization_),
    increment(increment_)
{
    if(initialization == nullptr)
    {
        initialization = new NullExpression();
    }
    if(increment == nullptr)
    {
        increment = new NullExpression();
    }
}

For::~For()
{
    delete initialization;
    delete increment;
}

int For::walkTree()
{
    return 0;
}

AstNode * For::getInitialization()
{
    return initialization;
}

Expression * For::getIncrement()
{
    return increment;
}

void For::fillSymbolTable(SymbolTableStack& stack)
{
    stack.push(symbolTable);
    initialization->fillSymbolTable(stack);
    
    for(auto child : children)
        child->fillSymbolTable(stack);

    if (Expression* expression = dynamic_cast<Expression*>(initialization))
    {
        if (!expression->checkNonVoidType(stack))
         {
            ErrorManager& errorManager = ErrorManager::getInstance();
		    errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_VOID_TYPE, "");
         }
    }

    if (!getCondition()->checkNonVoidType(stack))
    {
        ErrorManager& errorManager = ErrorManager::getInstance();
		errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_VOID_TYPE, "");
    }

    if (!increment->checkNonVoidType(stack))
    {
        ErrorManager& errorManager = ErrorManager::getInstance();
		errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_VOID_TYPE, "");
    }
}

void For::fillAstTrace(std::string& astTrace)
{
    astTrace += "FOR\n";
    for (auto child : children)
        child->fillAstTrace(astTrace);
}