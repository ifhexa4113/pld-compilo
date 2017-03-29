#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include "Type.h"
#include "LValueDeclaration.h"
#include "ast/definition/ArrayDefinition.h"

class ArrayDeclaration : public LValueDeclaration
{
public:
    ArrayDeclaration(std::string name, Type type, int size);
    ~ArrayDeclaration();
    virtual std::auto_ptr<ArrayDeclaration> clone() const;
    int getSize();
    int walkTree();
    ArrayDefinition* toEmptyDefinition();

protected:
    int size;
};

#endif
