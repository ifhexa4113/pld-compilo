#ifndef VARIABLE_H
#define VARIABLE_H

#include "LValue.h"

class Variable : public LValue
{
public:
    Variable(Type type) : LValue(type){};
    ~Variable() {};
};

#endif
