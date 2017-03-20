#ifndef ARRAY_H
#define ARRAY_H

#include "LValue.h"

class Array : public LValue
{
public:
    Array(Type type) : LValue(type){};
    virtual ~Array();
};

#endif
