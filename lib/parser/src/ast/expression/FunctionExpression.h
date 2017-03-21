#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <vector>

#include "Expression.h"

class Function : public Expression
{
public:
    Function(std::vector<Expression*> list_, string name_);
    virtual ~Function();

    virtual int walkTree();
    std::string getName() { return name; };

protected:
    std::vector<Expression*> parameters;
    std::string name;
};

#endif
