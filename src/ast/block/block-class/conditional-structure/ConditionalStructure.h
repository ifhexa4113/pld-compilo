
#ifndef CONDITIONALSTRUCTURE_H
#define CONDITIONALSTRUCTURE_H

#include "BlockClass.h"

class ConditionalStructure: public BlockClass{

public:
    ConditionalStructure();
    ~ConditionalStructure();

    virtual int WalkTree();

protected:
    Expression condition;
};

#endif //CONDITIONALSTRUCTURE_H
