#ifndef ARRAY_DEFINITION_H
#define ARRAY_DEFINITION_H

#include <string>
#include "Definition.h"

class ArrayDefinition : public Definition {
public:
    ArrayDefinition(std::string name_);
    ~ArrayDefinition();
    int walkTree();
};

#endif //ARRAY_DEFINITION_H
