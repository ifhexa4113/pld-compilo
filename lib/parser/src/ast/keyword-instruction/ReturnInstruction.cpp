#include <iostream>
#include "ReturnInstruction.h"
#include "ast/expression/NullExpression.h"

ReturnInstruction::ReturnInstruction(Expression* value_) :
    AstNode(),
    value(value_)
{
    if(value == nullptr) {
        value = new NullExpression();
    }
}

ReturnInstruction::~ReturnInstruction()
{
    delete value;
}

int ReturnInstruction::walkTree()
{
    std::cout << "Return node" << std::endl;
    return 0;
}

Expression * ReturnInstruction::getValue() const
{
    return value;
}

void ReturnInstruction::fillSymbolTable(SymbolTableStack& stack)
{
    value->fillSymbolTable(stack);
}