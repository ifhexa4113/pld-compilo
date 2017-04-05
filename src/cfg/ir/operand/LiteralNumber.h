#ifndef LITERALNUMBER_H
#define LITERALNUMBER_H

#include "Operand.h"

class Table;

class LiteralNumber: public Operand
{

    /**
     * The Table acts like an Operands' Priestess:
     * She's the only one able to create Registers
     * and manipulate them.
     */
    friend class Table;

public:
    /**
     * This is a the correct way of doing an operator= overload and so:
     * using the copy-and-swap idiom.
     * http://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
     */
    friend void swap(LiteralNumber& ln1, LiteralNumber& ln2);

    /**
     * Transforms the operand into a string,
     * in order to insert it in a stream for example.
     */
    std::string toString() const;

    // Classic destructor
    ~LiteralNumber();

private:
    LiteralNumber(int value_ = 0);                  // Classic
    LiteralNumber(LiteralNumber const & other);     // Copy
    LiteralNumber(LiteralNumber&& other);           // Move
    LiteralNumber& operator=(LiteralNumber other);  // With copy-and-swap idiom, so no const ref

};

#endif // LITERALNUMBER_H
