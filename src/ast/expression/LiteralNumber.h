#ifndef LITERAL_NUMBER_H    
#define LITERAL_NUMBER_H

#include <cstdint>

#include "Expression.h"

class LiteralNumber : public Expression
{
public:
    LiteralNumber(int64_t value);
    virtual ~LiteralNumber(){};

    virtual int walTree();
    std::string getValue() { return value; };

protected:
    int64_t value;
}

#endif