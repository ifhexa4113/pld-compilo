
#ifndef ELSE_H
#define ELSE_H

#include "BlockClass.h"

class Else : public BlockClass {

public:
    Else(Block* block_);
    virtual ~Else();
    virtual int walkTree();

};

#endif //ELSE_H
