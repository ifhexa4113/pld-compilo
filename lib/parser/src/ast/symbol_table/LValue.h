#ifndef LVALUE_H
#define LVALUE_H

#include <string>
#include "Type.h"
#include "Symbol.h"

class LValue : public Symbol
{
public:
    LValue(std::string name, Type type);
    virtual ~LValue();
};

#endif
