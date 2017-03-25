#ifndef LVALUE_H
#define LVALUE_H

#include <string>
#include "Type.h"
#include "Declaration.h"

class LValueDeclaration : public Declaration
{
public:
    LValueDeclaration(std::string name, Type type);
    virtual ~LValueDeclaration();
    virtual int walkTree() = 0;
};

#endif
