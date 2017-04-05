#ifndef IF_H
#define IF_H

#include <vector>
#include "ConditionalStructure.h"
#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class If: public ConditionalStructure
{
public:
	If(AstNode* condition_, std::vector<AstNode*> ifStat_, std::vector<AstNode*> elseStat_);
    ~If();
    int walkTree();

	Block* getIfBlock() { return ifBlock; };
	Block* getElseBlock() {return elseBlock; };

protected:
	Block* ifBlock;
	Block* elseBlock;

};

#endif //IF_H
