#include "ParenthesisExpression.h"
#include "NullExpression.h"

ParenthesisExpression::ParenthesisExpression(Expression* expression_) :
    Expression(),
    expression(expression_)
{
    if(expression == nullptr)
    {
        expression = new NullExpression();
    }
}

ParenthesisExpression::~ParenthesisExpression()
{
    delete expression;
}

int ParenthesisExpression::walkTree()
{
    return 0;
}

void ParenthesisExpression::fillSymbolTable(SymbolTableStack& stack)
{
    expression->fillSymbolTable(stack);
}

Type ParenthesisExpression::getType(SymbolTableStack& stack)
{
    return expression->getType(stack);
}

bool ParenthesisExpression::checkNonVoidType(SymbolTableStack& stack) {
    return expression->checkNonVoidType(stack);
}

void ParenthesisExpression::fillAstTrace(std::string& astTrace)
{
    astTrace += "PARENTHESIS EXPR\n";
}