#include <iostream>
#include "LiteralNumberExpression.h"

LiteralNumberExpression::LiteralNumberExpression(int64_t value_) :
    Expression(),
    value(value_)
{
    // Nothing else to do
}

int LiteralNumberExpression::walkTree()
{
    std::cout << value;
    return 0;
}

int64_t LiteralNumberExpression::getValue()
{
    return value;
}

Type LiteralNumberExpression::getType(SymbolTableStack&)
{
    return Type::INT64_T;
}

