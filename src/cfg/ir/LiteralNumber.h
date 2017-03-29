//
// Created by charles on 2017-03-29.
//

#ifndef LITERALNUMBER_H
#define LITERALNUMBER_H

#include "Operand.h"

class LiteralNumber: public Operand {
public:
    LiteralNumber(int value_);
    ~LiteralNumber();

    std::string toString();

};

#endif // LITERALNUMBER_H
