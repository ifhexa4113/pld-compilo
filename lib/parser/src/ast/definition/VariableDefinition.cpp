#include "VariableDefinition.h"
#include "ast/expression/NullExpression.h"
#include "ast/expression/FunctionExpression.h"
#include "ast/ErrorManager.h"

VariableDefinition::VariableDefinition(LValueDeclaration* declaration_, Expression* rExpression_) :
    Definition(declaration_),
    rExpression(rExpression_)
{
    if(rExpression == nullptr)
    {
        rExpression = new NullExpression();
    }
}

VariableDefinition::~VariableDefinition()
{
    delete rExpression;
}

int VariableDefinition::walkTree()
{
    return 0;
}

Expression * VariableDefinition::getRExpression()
{
    return rExpression;
}

void VariableDefinition::fillSymbolTable(SymbolTableStack& stack)
{
    Definition::fillSymbolTable(stack);
    rExpression->fillSymbolTable(stack);
    if (FunctionExpression* functionExpression = dynamic_cast<FunctionExpression*>(rExpression))
        {
            Type functionExpressionType = functionExpression->getType(stack);
            if (functionExpressionType == Type::VOID_T)
            {
                ErrorManager& errorManager = ErrorManager::getInstance();
                errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_VOID_TYPE, "");
            }
        }
        else if (Expression* castExpression = dynamic_cast<Expression*>(rExpression))
            castExpression->getType(stack);
}