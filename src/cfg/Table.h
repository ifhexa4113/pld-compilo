#ifndef PLD_COMPILO_TABLE_H
#define PLD_COMPILO_TABLE_H

#include <map>
#include <string>

#include "RegisterInfo.h"
#include "ir/operand/Register.h"

class Table
{
public:
    Table();
    ~Table();

    /**
     * Returns the register associated to the var if it already exists,
     * or a nullptr otherwise.
     * @param associatedVar The var UNIQUE name you're looking for
     */
    Register* getRegister(std::string associatedVar);

    /**
     * Returns the info associated to the given register if it already exists,
     * or an empty RegisterInfo otherwise ({type: Type::VOID_T, offset: -1}).
     * @param reg The register you're looking for.
     */
    RegisterInfo getRegisterInfo(Register* reg);

    /**
     * Inserts a register into the table.
     * This does NOT ensure that the register / variable already exists in the table,
     * i.e. it will overwrite any existing register / variable.
     * If no name is provided, the default one is "$tempX",
     * where X is an unsigned int from 0 to max(unsigned int).
     * @param reg The register to insert.
     * @param associatedVar The variable's UNIQUE name to insert.
     * @param type The variable's type. Default to Type::INT64_T.
     */
    void addRegister(Register* reg, std::string associatedVar = Table::TEMP_VAR, Type type = Type::INT64_T);

    // TODO, 'cause that's nice:
    // Register* getOrCreateRegister(std::string associatedVar);

protected:
    std::map<std::string, Register*> varToReg;
    std::map<Register*, RegisterInfo> regToInfo;

    static unsigned int tempCounter;
    static const std::string TEMP_VAR;
};


#endif //PLD_COMPILO_TABLE_H
