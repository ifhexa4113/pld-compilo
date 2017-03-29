#ifndef OPERAND_H
#define OPERAND_H

#include <string>
#include <ostream>

class Operand {
public:
    Operand(int value_);
    ~Operand();

    int getValue();
    friend std::ostream& operator<<(std::ostream& os, const Operand& dt);
    virtual std::string toString() = 0;

protected:
    int value;
};

#endif //OPERAND_H
