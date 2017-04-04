//
// Created by Element on 02/04/2017.
//

#ifndef PLD_COMPILO_IRABTRACTTRANSLATOR_H
#define PLD_COMPILO_IRABTRACTTRANSLATOR_H

#include <string>
#include "AbstractBasicBlockAssembler.h"


/**
 * Base class for all Assembler instructions
 */
class IRAbstractAssembler {
public:
    IRAbstractAssembler(AbstractBasicBlockAssembler * parent_block);
    virtual ~IRAbstractAssembler();

    virtual std::string translate() const = 0;

protected:
    AbstractBasicBlockAssembler * parent_block;
};


#endif //PLD_COMPILO_IRABTRACTTRANSLATOR_H
