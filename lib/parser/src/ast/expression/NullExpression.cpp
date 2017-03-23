#include "NullExpression.h"

NullExpression::NullExpression() : Expression()
{
    // Nothing else to do
}

int NullExpression::walkTree()
{
    return 0;
}
