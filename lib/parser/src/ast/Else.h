#ifndef ELSE_H
#define ELSE_H

#include "ast/AstNode.h"

class Else : public AstNode {

public:
    Else();
    ~Else();
    int walkTree();
};

#endif //ELSE_H
