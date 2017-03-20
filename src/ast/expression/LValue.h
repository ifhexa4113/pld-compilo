#ifndef L_VALUE_H
#define L_VALUE_H

#include <string>

#include "Expression.h"

class LValue : public Expression
{
public:
    Expression(std::string name);
    virtual ~Expression(){};

    virtual int walTree();
    std::string getName() { return name; };

protected:
    std::string name;
}

#endif