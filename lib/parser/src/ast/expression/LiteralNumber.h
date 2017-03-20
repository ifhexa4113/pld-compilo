#ifndef LITERAL_NUMBER_H    
#define LITERAL_NUMBER_H

#include <cstdint>

#include "Expression.h"

class LiteralNumber : public Expression
{
public:
    LiteralNumber(int64_t value_);
    virtual ~LiteralNumber(){};

    virtual int walkTree();
    int64_t getValue() { return value; };

protected:
    int64_t value;
};

#endif