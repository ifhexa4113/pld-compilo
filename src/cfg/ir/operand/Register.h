#ifndef REGISTER_H
#define REGISTER_H

#include "Operand.h"

class Table;

class Register: public Operand
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
    friend void swap(Register& reg1, Register& reg2);

    /**
     * To allow a Register to be inserted in a stream
     * as a string.
     * @return
     */
    std::string toString() const;

    // Classic destructor
    ~Register();

    // Getters
    std::string getName() const;
    int getValue() const;

protected:
    /**
     * The register's name.
     */
    std::string name;

    /**
     * To name Registers uniquely.
     */
    static unsigned int nextRegister;

private:
    /**
     * All constructors (and operator=) are private,
     * so Table is the only one able to construct a Register.
     */

    Register(int value_ = 0);                   // Classic
    Register(std::string name_, int value_);    // Classic
    Register(Register const & other);           // Copy
    Register(Register&& other);                 // Move
    Register& operator=(Register reg);          // With copy-and-swap idiom, so no const ref
};


#endif //REGISTER_H
