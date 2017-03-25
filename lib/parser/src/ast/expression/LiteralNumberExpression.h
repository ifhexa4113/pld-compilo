#ifndef LITERAL_NUMBER_H    
#define LITERAL_NUMBER_H

#include <cstdint>
#include "Expression.h"

class LiteralNumber : public Expression
{
public:
    LiteralNumber(int64_t value_);
    ~LiteralNumber(){};
    int walkTree();
    int64_t getValue();

protected:
    int64_t value;
};

#endif