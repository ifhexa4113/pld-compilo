#include "For.h"
#include "ast/expression/NullExpression.h"

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
    initialization->fillTableSymbol(stack);
    for(auto child : children)
        child->fillTableSymbol(stack);

}