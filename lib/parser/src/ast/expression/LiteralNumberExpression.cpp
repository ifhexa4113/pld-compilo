#include <iostream>
#include "LiteralNumberExpression.h"

LiteralNumber::LiteralNumber(int64_t value_) :
    Expression(),
    value(value_)
{
    // Nothing else to do
}

int LiteralNumber::walkTree()
{
    std::cout << value;
    return 0;
}

int64_t LiteralNumber::getValue()
{
    return value;
}

