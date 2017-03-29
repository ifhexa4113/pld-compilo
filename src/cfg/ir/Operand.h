//
// Created by charles on 2017-03-29.
//

#ifndef OPERAND_H
#define OPERAND_H

#include <string>

class Operand {
public:
    Operand(int value_);
    ~Operand();

    int getValue();

    friend ostream& operator<<(ostream& os, const Operand& dt);
    virtual std::string toString() = 0;

protected:
    int value;
};

#endif //OPERAND_H
