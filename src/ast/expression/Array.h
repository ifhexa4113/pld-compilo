#ifndef ARRAY_H
#define ARRAY_H

#include "LValue.h"

class Array : public LValue
{
public:
    Array(std::string name, Expression* index)
    ~Array();

protected:
    Expression* index;
};

#endif