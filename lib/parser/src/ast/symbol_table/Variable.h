#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Type.h"
#include "LValue.h"

class Variable : public LValue
{
public:
    Variable(std::string name, Type type);
    ~Variable();
};

#endif
