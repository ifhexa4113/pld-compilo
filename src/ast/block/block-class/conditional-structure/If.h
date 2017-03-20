
#ifndef IF_H
#define IF_H

#include "ConditionalStructure.h"

class BlockClass: public ConditionalStructure{

public:
    If();
    ~If();
    virtual int WalkTree();

};

#endif //IF_H
