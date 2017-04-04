#include "While.h"

While::While(Expression* condition_) :
    ConditionalStructure(condition_)
{
    // Nothing else to do
}

While::While(Expression* condition_, std::vector<AstNode*> children_) :
    ConditionalStructure(condition_, children_)
{
    // Nothing else to do
}

While::~While()
{
    // Nothing else to do
}

int While::walkTree()
{
    return 0;
}

void While::fillAstTrace(std::string& astTrace)
{
    astTrace += "WHILE\n";
    for (auto child : children)
        child->fillAstTrace(astTrace);
}