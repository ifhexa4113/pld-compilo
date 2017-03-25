#ifndef ARRAY_DEFINITION_H
#define ARRAY_DEFINITION_H

#include "Definition.h"
#include "ast/declaration/LValueDeclaration.h"

class ArrayDefinition : public Definition {
public:
    ArrayDefinition(LValueDeclaration* declaration_);
    ~ArrayDefinition();
    int walkTree();
};

#endif //ARRAY_DEFINITION_H
