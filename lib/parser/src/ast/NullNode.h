#ifndef NULL_NODE_H
#define NULL_NODE_H

#include "ast/AstNode.h"

class NullNode : public AstNode
{
public:
    NullNode();
    ~NullNode();
    int walkTree();
    void fillAstTrace(std::string& astTrace);
};

#endif //NULL_NODE_H
