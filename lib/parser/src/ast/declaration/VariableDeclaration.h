#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Type.h"
#include "LValueDeclaration.h"

class VariableDeclaration : public LValueDeclaration
{
public:
    VariableDeclaration(std::string name, Type type);
    ~VariableDeclaration();
    int walkTree();
};

#endif
