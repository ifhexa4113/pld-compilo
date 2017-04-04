#include "ArrayDefinition.h"

ArrayDefinition::ArrayDefinition(LValueDeclaration* declaration_) :
    Definition(declaration_)
{
    // Nothing else to do
}

ArrayDefinition::~ArrayDefinition()
{
    // Nothing else to do
}

int ArrayDefinition::walkTree()
{
    return 0;
}

void ArrayDefinition::fillAstTrace(std::string& astTrace)
{
    astTrace += "ARRAY DEF\n";
}