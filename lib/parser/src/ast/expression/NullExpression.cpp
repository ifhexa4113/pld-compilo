#include "NullExpression.h"

NullExpression::NullExpression() : Expression()
{
    // Nothing else to do
}

NullExpression::~NullExpression()
{
    // Nothing else to do
}

int NullExpression::walkTree()
{
    return 0;
}

Type NullExpression::getType(SymbolTableStack&)
{
    return Type::VOID_T;
}
