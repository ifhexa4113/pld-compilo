
#ifndef BLOCKCLASS_H
#define BLOCKCLASS_H

#include "AstNode.h"

class BlockClass: public AstNode{

public:
    BlockClass();
    ~BlockClass();

    virtual int WalkTree();

protected:
    Block* block;
};

#endif //BLOCKCLASS_H
