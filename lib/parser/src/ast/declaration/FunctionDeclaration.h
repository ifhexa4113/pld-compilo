#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "Type.h"
#include "Declaration.h"

class FunctionDeclaration : public Declaration
{
public:
    FunctionDeclaration(std::string name, Type type, int nbArgs);
    ~FunctionDeclaration();
    int walkTree();
    int getNbArgs();

protected:
    int nbArgs;
};

#endif
