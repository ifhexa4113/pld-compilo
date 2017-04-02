#ifndef LITERALNUMBER_H
#define LITERALNUMBER_H

#include "Operand.h"

class LiteralNumber: public Operand {
public:
    LiteralNumber(int value_);
    ~LiteralNumber();

    std::string toString() const;

};

#endif // LITERALNUMBER_H
