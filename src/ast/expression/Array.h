#ifndef ARRAY_H
#define ARRAY_H

#include "LValue.h"

class Array : public LValue
{
public:
    Array(std::string name, Expression* index)
    virtual ~Array();

    virtual int walkTree();

protected:
    Expression* index;
};

#endif