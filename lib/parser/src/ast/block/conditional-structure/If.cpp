#include "If.h"

If::If(AstNode* condition_, std::vector<AstNode*> ifStat_, std::vector<AstNode*> elseStat_) :
	ConditionalStructure(dynamic_cast<Expression*>(condition_)),
	ifBlock(new Block(ifStat_)),
	elseBlock(new Block(elseStat_))
{
	addChildren(ifBlock);
	addChildren(elseBlock);
}

If::~If()
{
    // Nothing else to do
}

int If::walkTree()
{
    return 0;
}

void If::fillAstTrace(std::string& astTrace)
{
	astTrace += "IF\n";
	for (auto child : children)
        child->fillAstTrace(astTrace);
}