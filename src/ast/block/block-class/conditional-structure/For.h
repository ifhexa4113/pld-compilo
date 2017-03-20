
#ifndef FOR_H
#define FOR_H

#include "ConditionalStructure.h"

class For: public ConditionalStructure{

public:
    For();
    ~For();

    virtual int WalkTree();

protected:
    Expression initialization;
    Expression increment;
};

#endif //FOR_H
