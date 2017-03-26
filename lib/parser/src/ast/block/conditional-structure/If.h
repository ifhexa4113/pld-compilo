#ifndef IF_H
#define IF_H

#include <vector>
#include "ConditionalStructure.h"
#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class If: public ConditionalStructure
{
public:
    If(Expression* condition_);
    If(Expression* condition_, std::vector<AstNode*> children_);
	If(AstNode*& condition, std::vector<AstNode*>*& ifStat, std::vector<AstNode*>*& elseStat);
    ~If();
    int walkTree();

protected:
	std::vector<AstNode*> ifStat;
	std::vector<AstNode*> elseStat;
};

#endif //IF_H
