#ifndef FOR_H
#define FOR_H

#include <vector>
#include "ConditionalStructure.h"
#include "ast/AstNode.h"
#include "ast/expression/Expression.h"

class For: public ConditionalStructure
{
public:
    For(Expression* condition_, AstNode* initialization_, Expression* increment_);
    For(Expression* condition_, AstNode* initialization_, Expression* increment_, std::vector<AstNode*> children_);
    ~For();
    int walkTree();
	AstNode* getInitialization();
    Expression* getIncrement();

protected:
    AstNode* initialization; // TODO : can be a declaration
    Expression* increment;
};

#endif //FOR_H
