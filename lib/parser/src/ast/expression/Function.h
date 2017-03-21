

#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

#include "Function.h"
class Function : public Expression
{
public:
    Function(std::vector<Expression*> list, string name_);
    virtual ~Function()(){};

    virtual int walkTree();
    std::string getName() { return name; };

protected:
    std::string name;
};
#endif
