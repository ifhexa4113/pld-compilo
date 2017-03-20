#ifndef LVALUE_H
#define LVALUE_H

#include "Type.h"

class LValue
{
public:
    LValue(Type type);
    virtual ~LValue();

    Type getType();

protected:
    Type type;
};


#endif
