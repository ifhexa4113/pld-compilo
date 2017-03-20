
#ifndef IF_H
#define IF_H

#include "ConditionalStructure.h"
#include "../../../expression/Expression.h"

class If: public ConditionalStructure {

public:
    If(Block* block_, Expression* condition_);
    ~If();

    virtual int walkTree();

};

#endif //IF_H
