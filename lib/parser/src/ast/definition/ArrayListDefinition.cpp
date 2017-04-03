#include "ArrayListDefinition.h"
#include "ast/expression/FunctionExpression.h"
#include "ast/ErrorManager.h"

ArrayListDefinition::ArrayListDefinition(LValueDeclaration* declaration_, std::vector<Expression*> listExpression_) :
    Definition(declaration_),
    listExpression(listExpression_)
{
    // Nothing else to do
}

ArrayListDefinition::~ArrayListDefinition()
{
    for(auto expression : listExpression)
    {
        delete expression;
    }
}

int ArrayListDefinition::walkTree()
{
    return 0;
}

std::vector<Expression *> ArrayListDefinition::getListExpression()
{
    return listExpression;
}

void ArrayListDefinition::fillSymbolTable(SymbolTableStack& stack)
{
    Definition::fillSymbolTable(stack);
    for(auto expression : listExpression)
    {
        expression->fillSymbolTable(stack);
        if (FunctionExpression* functionExpression = dynamic_cast<FunctionExpression*>(expression))
        {
            Type functionExpressionType = functionExpression->getType(stack);
            if (functionExpressionType == Type::VOID_T)
            {
                ErrorManager& errorManager = ErrorManager::getInstance();
                errorManager.addEncounteredError(ErrorManager::INAPPROPRIATE_VOID_TYPE, "");
            }
        }
        else if (Expression* castExpression = dynamic_cast<Expression*>(expression))
            castExpression->getType(stack);
    }    
}