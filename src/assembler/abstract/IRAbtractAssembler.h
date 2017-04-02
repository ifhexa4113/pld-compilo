//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_IRABTRACTTRANSLATOR_H
#define PLD_COMPILO_IRABTRACTTRANSLATOR_H

#include <string>

/**
 * Base class for all Assembler instructions
 */
class IRAbtractAssembler {
public:
    IRAbtractAssembler();
    virtual ~IRAbtractAssembler() = 0;

    virtual std::string translate() const = 0;
};


#endif //PLD_COMPILO_IRABTRACTTRANSLATOR_H
