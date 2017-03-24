#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "Type.h"
#include "Symbol.h"

class Function : public Symbol
{
public:
    Function(std::string name, Type type, int nbArgs);
    virtual ~Function();
    int getNbArgs();

protected:
    int nbArgs;
};

#endif
