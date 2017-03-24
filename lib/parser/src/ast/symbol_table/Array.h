#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include "Type.h"
#include "LValue.h"

class Array : public LValue
{
public:
    Array(std::string name, Type type, int size);
    virtual ~Array();
    int getSize();

protected:
    int size;
};

#endif
