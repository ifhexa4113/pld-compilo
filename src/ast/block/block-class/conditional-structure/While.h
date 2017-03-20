
#ifndef WHILE_H
#define WHILE_H

#include "ConditionalStructure.h"

class While: public ConditionalStructure{

public:
    While();
    ~While();
    virtual int WalkTree();

};

#endif //WHILE_H
