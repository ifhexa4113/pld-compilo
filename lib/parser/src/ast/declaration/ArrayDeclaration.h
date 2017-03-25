#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include "Type.h"
#include "LValueDeclaration.h"

class ArrayDeclaration : public LValueDeclaration
{
public:
    ArrayDeclaration(std::string name, Type type, int size);
    ~ArrayDeclaration();
    int getSize();
    int walkTree();

protected:
    int size;
};

#endif
