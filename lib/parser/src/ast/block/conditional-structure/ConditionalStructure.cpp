#include "ConditionalStructure.h"
#include "ast/expression/NullExpression.h"
#include "ast/expression/FunctionExpression.h"
#include "ast/ErrorManager.h"
#include <iostream>

ConditionalStructure::ConditionalStructure(Expression* condition_) :
    Block(),
    condition(condition_)
{
    if(condition == nullptr)
    {
        condition = new NullExpression();
    }
}

ConditionalStructure::ConditionalStructure(Expression *condition_, std::vector<AstNode *> children_) :
    Block(children_),
    condition(condition_)
{
    if(condition == nullptr)
    {
        condition = new NullExpression();
    }
}

ConditionalStructure::~ConditionalStructure()
{
    delete condition;
}

int ConditionalStructure::walkTree()
{
    return 0;
}

Expression * ConditionalStructure::getCondition()
{
    return condition;
}

void ConditionalStructure::fillSymbolTable(SymbolTableStack& stack)
{
    condition->fillSymbolTable(stack);
    Block::fillSymbolTable(stack);

    if (!condition->checkNonVoidType(stack))
    {
        ErrorManager& errorManager = ErrorManager::getInstance();
        errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_VOID_TYPE, "");
    }
}