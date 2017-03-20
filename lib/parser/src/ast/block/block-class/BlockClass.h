
#ifndef BLOCKCLASS_H
#define BLOCKCLASS_H

#include "../../AstNode.h"
#include "../Block.h"

class BlockClass: public AstNode{

public:
    BlockClass(Block* block_);
    ~BlockClass();

    virtual int walkTree();

protected:
    Block* block;
};

#endif //BLOCKCLASS_H
