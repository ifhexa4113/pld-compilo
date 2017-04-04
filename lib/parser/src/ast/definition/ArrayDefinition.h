#ifndef ARRAY_DEFINITION_H
#define ARRAY_DEFINITION_H

#include "Definition.h"
#include "ast/declaration/LValueDeclaration.h"

class ArrayDefinition : public Definition {
public:
    ArrayDefinition(LValueDeclaration* declaration_);
    ~ArrayDefinition();
    int walkTree();
    void fillAstTrace(std::string& astTrace);

    // TODO missing an expression !
};

#endif //ARRAY_DEFINITION_H
