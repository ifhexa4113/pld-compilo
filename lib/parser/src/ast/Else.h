#ifndef ELSE_H
#define ELSE_H

#include "AstNode.h"

class Else : public AstNode {

public:
    Else();
    ~Else();
    int walkTree();
};

#endif //ELSE_H
