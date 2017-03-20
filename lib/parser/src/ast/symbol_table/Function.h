#ifndef FUNCTION_H
#define FUNCTION_H

#include "Type.h"

class Function
{
public:
    Function(Type type);
    virtual ~Function();

    Type getType();
    int getNbArgs();

protected:
    Type returnType;
    int nbArgs;
};

#endif
