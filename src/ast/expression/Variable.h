#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

#include "LValue.h"

class Variable : public LValue
{
public:
    Variable(std::string name);
    virtual ~Variable(){};

    virtual int walTree();

}

#endif